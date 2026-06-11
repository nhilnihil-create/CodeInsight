#include<stdio.h>

int main()
{
    int n, x, m[1005], i, sum=0, min=1002, total;

    scanf("%d %d", &n, &x);

    for(i=0; i<n; i++){
        scanf("%d", &m[i]);
        sum += m[i];
        if(m[i]<min)
            min=m[i];
    }

    x = x-sum;

    if(x > min){
        total = n+ x/min;
    }
    else
        total = n;

    printf("%d\n", total);

    return 0;
}

