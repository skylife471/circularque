#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 50

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}queuetype;

int is_full(queuetype* q)
{
    return(q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}
int is_empty(queuetype* q)
{
    return(q->rear == q->front);
}
void init_queue(queuetype* q)
{
    q->front = 0;
    q->rear = 0;
}
void enqueue(queuetype* q, element item)
{
    if (is_full(q))
    {
        fprintf(stderr, "큐 포화 에러");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}
void queue_print(queuetype* q)
{
    printf("QUEUE(front=%d rear =%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}
element dequeue(queuetype* q)
{
    if (is_empty(q))
    {
        fprintf(stderr, "큐 저장 안됐음 에러");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}
int main(void)
{
    queuetype q;
    int element;
    init_queue(&q);
    for (;;)
    {
        printf("=====MENU=====\n");
        printf("1. Input data and Enqueue\n");
        printf("2. Dequeue and print data\n");
        printf("3. Print data\n");
        printf("4. Exit\n");
        int input = 0;
        printf("Select number: ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            if (is_full(&q))
            {
                printf("Queue is Full!\n");
                break;
            }
            while (!is_full(&q))
            {
                printf("Input the data:");
                scanf("%d", &element);
                enqueue(&q, element);
                printf("Enqueue : %d\n", element);
                break;

            }
            break;


        case 2:
            if (is_empty(&q))
            {
                printf("Queue is empty\n");
                break;
            }
            else
            {
                element = dequeue(&q);
                printf("dequeue: %d\n", element);
                break;
            }
        case 3:
            if (is_empty(&q))
            {
                printf("Queue is empty!\n");
                break;
            }
            queue_print(&q);
            break;
        case 4:
            printf("Exit the program");
            return;
        }
    }
    return 0;
}