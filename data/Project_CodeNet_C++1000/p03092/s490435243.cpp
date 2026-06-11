#include<bits/stdc++.h>
#define ll long long
#define maxn 5001
#define inf 1000000000000000000
ll p[maxn], pos[maxn], dp[maxn][maxn];
using namespace std;
int main()
{
    ll n, a, b, ans=inf;
    cin>>n>>a>>b;
    for(int i=1; i<=n; i++) cin>>p[i], pos[p[i]]=i;
    memset(dp, 1000000, sizeof dp);
    dp[0][0]=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if(pos[i]>pos[j]){
                dp[i][i]=min(dp[i-1][j], dp[i][i]);
                dp[i][j]=dp[i-1][j]+b;
            }
            else dp[i][j]=dp[i-1][j]+a;
        }
    }
    for(int i=1; i<=n; i++) ans=min(ans, dp[n][i]);
    cout<<ans;
}