#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;

int main(){
    int N; cin>>N;
    vector<double> p(N); rep(i,N)cin>>p[i];
    vector<vector<double>> dp(N+1,vector<double>(N+1,0.0));
    dp[0][0] = 1.0;
    rep(n,N){
        rep(j,n+1){
            dp[n+1][j+1] += dp[n][j]*p[n];
            dp[n+1][j] += dp[n][j]*(1-p[n]);
        }
    }
    double res = 0.0;
    for(int i = N/2+1; i<=N; i++) res += dp[N][i];
    cout << fixed << setprecision(10) << res << endl;
}