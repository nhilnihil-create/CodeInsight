#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=1e5+10;
int n;
char s[maxn];
void judge()
{
    if(s[1]=='0' || s[n]=='1')
    {
        printf("-1\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1' && s[n-i]=='0')
        {
            printf("-1\n");
            return;
        }
    }
    int root=1;
    for(int i=2;i<=n;i++)
    {
        printf("%d %d\n",root,i);
        if(s[i-1]=='1') root=i;
    }
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    judge();
}
