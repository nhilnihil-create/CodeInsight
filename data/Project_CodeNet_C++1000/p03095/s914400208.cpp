#include <bits/stdc++.h>
using namespace std;
#define Maxn 100007
#define modp 1000000007
int n;
char s[Maxn];
int cnt[27];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for (int i=1;i<=n;i++)
        ++cnt[s[i]-'a'+1];
    int ans=1;
    for (int i=1;i<=26;i++)
        ans=(1LL*ans*(cnt[i]+1))%modp;
    ans=(ans+modp-1)%modp;
    printf("%d\n",ans);
    return 0;
}