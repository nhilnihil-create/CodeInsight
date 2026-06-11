#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF=1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; ll A,B; cin >> N >> A >> B;
    vector<int> p(N);
    for (int i=0;i<N;++i) cin >> p[i];
    vector<vector<ll>> dp(N+1,vector<ll>(N+1,INF));
    dp[0][0]=0;
    for (int i=0;i<N;++i){
        for (int j=0;j<=N;++j){
            if (p[i]>j){
                dp[i+1][p[i]]=min(dp[i+1][p[i]],dp[i][j]);
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+A);
            } else dp[i+1][j]=min(dp[i+1][j],dp[i][j]+B);
        }
    }
    ll ans=INF;
    for (int j=0;j<=N;++j) ans=min(ans,dp[N][j]);
    cout << ans << '\n';
}