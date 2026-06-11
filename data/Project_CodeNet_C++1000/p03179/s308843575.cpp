#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
int n;
char str[3300];
ll dp[3300][3300];
int main() {
    scanf("%d%s",&n,str+2);
    dp[1][1]=1;
    for(int i=2;i<=n;i++)
        if(str[i]=='<')
            for(int j=2;j<=i;j++)
                dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%mod;
        else
            for(int j=i-1;j;j--)
                dp[i][j]=(dp[i][j+1]+dp[i-1][j])%mod;
    ll ans=0;
    for(int i=1;i<=n;i++)ans=(ans+dp[n][i])%mod;
    printf("%lld\n",ans);
    return 0;
}