#include<stdio.h>

int main()
{
    int N, M, X, A[101], x_to_zero=0, x_to_n=0, i;

    scanf("%d %d %d", &N, &M, &X);

    for(i=0; i<M; i++){
        scanf("%d", &A[i]);
    }

    for(i=0; i<M; i++){
        if(A[i]>X)
            x_to_n++;
        else
            x_to_zero++;
    }

    if(x_to_n<x_to_zero)
        printf("%d\n", x_to_n);
    else
        printf("%d\n", x_to_zero);

    return 0;
}
