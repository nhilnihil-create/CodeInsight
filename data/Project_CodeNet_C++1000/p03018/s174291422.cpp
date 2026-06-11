#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
char s[Maxn],a[Maxn];
int n;
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    int m=0;
    for (int i=1;i<=n;i++)
        if (s[i]!='C') a[++m]=s[i];
        else if (m>0&&a[m]=='B') a[m]='D';
        else a[++m]=s[i];
    long long ans=0LL;
    int tmp=0;
    for (int i=m;i;i--)
        if (a[i]=='A') ans+=tmp;
        else if (a[i]=='D') ++tmp;
        else tmp=0;
    printf("%lld\n",ans);
    return 0;
}