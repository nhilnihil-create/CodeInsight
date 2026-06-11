#include<bits/stdc++.h>
#define LL long long
#define inf 0x3fffffffffffffff
using namespace std;

int n,m;
char s[5010];
struct data
{
    int len;
    char s[10];
}a[50010];

bool cmp(data x,data y)
{
    int len=min(x.len,y.len);
    for (int i=1;i<=len;i++)
        if (x.s[i]!=y.s[i]) return x.s[i]<y.s[i];
    return x.len<y.len;
}

bool com(data x,data y)
{
    int len=min(x.len,y.len);
    if (x.len!=y.len) return false;
    for (int i=1;i<=len;i++)
        if (x.s[i]!=y.s[i]) return false;
    return true;
}

int main()
{
    scanf("%s%d",s+1,&m);
    n=strlen(s+1);
    string x;
    int p=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=2*m;j++)
        {
            if (i+j-1>n) break;
            p++;a[p].len=j;
            for (int k=1;k<=j;k++)
                a[p].s[k]=s[i+k-1];
        }
    }
    sort(a+1,a+1+p,cmp);
    m--;
    if (m==0)
    {
        for (int i=1;i<=a[1].len;i++)
            putchar(a[1].s[i]);
        puts("");
        return 0;
    }
    else
    {
        for (int i=2;i<=p;i++)
            if (!com(a[i],a[i-1]))
            {
                m--;
                if (m==0)
                {
                    for (int j=1;j<=a[i].len;j++)
                        putchar(a[i].s[j]);
                    puts("");
                    return 0;
                }
            }
        
    }
    return 0;
}