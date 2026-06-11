#include <stdio.h>

int main(void)
{
    int i,j;
    int A[20];
    int B[20];
    int N,M,C;
    int ret = 0;
    int sum;
    scanf("%d %d %d",&N,&M,&C);
    for(i = 0 ; i < M ; i++){
        scanf("%d",&(B[i]));
    }
    for(i = 0 ; i < N; i++){
        sum = 0;
        for(j = 0 ; j < M ; j++){
            scanf("%d",&(A[j]));
            sum += B[j]*A[j];
        }
        //条件を満たすか判定する
        if((sum + C) > 0){
            ret++;
        }
    }
    printf("%d\n",ret);
    return 0;
}
