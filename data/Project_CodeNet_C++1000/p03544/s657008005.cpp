#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=200010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int dp[N];
signed main()
{
    dp[0]=2, dp[1]=1;
    int n=read();
    for(ri int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
    printf("%lld\n",dp[n]);
    return 0;
}