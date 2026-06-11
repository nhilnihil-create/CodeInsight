#include<stdio.h>
#include<string.h>
char s[1005];
int main()
{
    int n;
    while(~scanf("%d",&n)){
        scanf("%s",s);
        int a=0,b=0;
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='R')
                a++;
            else
                b++;
        }
        if(a>b)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}