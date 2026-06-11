#include<stdio.h>
int main()
{
    int money,coin,i,j,k,l ;
    scanf("%d%d",&money,&coin);
    if((money % 500)<=coin)
    {
        printf("Yes");
    }
    else if(money<coin || money%500==0){
         printf("Yes");
    }
    else{
            printf("No");
    }
    return 0;
}
