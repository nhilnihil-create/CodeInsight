#include<cstdio>
#include<cstring>
#include<algorithm>
char s[10];
int main()
{
    scanf("%s",s);
    for(int i=0;i<(int)strlen(s);i++)
    {
        if(s[i]=='1')
        {
            s[i]='9';
            continue;
        }
        if(s[i]=='9') s[i]='1';
    }
    printf("%s",s);
}
