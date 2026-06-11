#include <bits/stdc++.h>
#define INF 1LL<<60
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
ll a,b;
int p[5005];
ll dp[5005][5005];

int main(void){
    scanf("%d%lld%lld",&n,&a,&b);
    for(int i=0;i<n;i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            if(j>p[i]){
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+b);
            }
            if(j==p[i]){
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
            }
            if(j<p[i]){
                dp[i+1][p[i]+1]=min(dp[i+1][p[i]+1],dp[i][j]);
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a);
            }
        }
    }
    ll ans=INF;
    for(int i=0;i<=n;i++){
        ans=min(dp[n][i],ans);
    }
    printf("%lld\n",ans);
    return 0;
}