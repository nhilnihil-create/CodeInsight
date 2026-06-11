#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int op= 1;
    for(int i = 0;i<n;i++)
    {
        if(op< k) op *= 2    ;
        else{
            op +=k;
        }
    }
    printf("%d\n",op);
}
