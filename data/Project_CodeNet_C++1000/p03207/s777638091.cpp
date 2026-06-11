#include<stdio.h>

int main()
{
    int N, max=-1, p[100000], sum=0, i=0;

    scanf("%d", &N);

    while(i != N)
    {
        scanf("%d", &p[i]);
        if(p[i] > max)
            max = p[i];
        sum = sum + p[i];
        i++;
    }

    sum = sum - max + (max/2);

    printf("%d\n", sum);

    return 0;
}
