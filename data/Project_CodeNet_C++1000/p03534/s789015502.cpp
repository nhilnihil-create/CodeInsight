#include <stdio.h>
int num[3];
int min(int x,int y)
{
    return (x>y?y:x);
}
int main()
{
    num[0]=num[1]=num[2];
    char s[100100];
    scanf("%s",s);
    for(int i=0;s[i];i++)
    {
        num[(s[i]-'a')]++;
    }
    int minn=min(num[0],min(num[1],num[2]));
    num[0]-=minn;
    num[1]-=minn;
    num[2]-=minn;
    if(num[0]>1||num[1]>1||num[2]>1)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
    return 0;
}
