#include<stdio.h>
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(((a-b)<=d&&(b-c)<=d&&(a-b)>=-d&&(b-c)>=-d)||((a-c)<=d&&(a-c)>=-d))
    printf("Yes\n");
    else
        printf("No\n");
}