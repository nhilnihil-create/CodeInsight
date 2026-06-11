#include<bits/stdc++.h>
using namespace std;

// template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
// template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    int N; cin>>N;
    vector<double> p(N); rep(i,N)cin>>p[i];
    vector<vector<double>> dp(N+1,vector<double>(N+1,0));
    dp[0][0] = 1;
    // rep1(i,N){
    //     for(int j = 1; j <= i; j++){
    //         dp[i][j] = dp[i-1][j-1] * p[i-1] + dp[i-1][j] * (1.0-p[i]);//j==iのとき不都合
    //     }
    // }
    rep(i,N){
        for(int j = 0; j <= i; ++j){
            dp[i+1][j+1] += dp[i][j]*p[i];
            dp[i+1][j] += dp[i][j]*(1-p[i]);
        }
    }
    double res = 0;
    for(int i = N/2+1; i <= N; i++){
        res += dp[N][i];
    }
    cout<<setprecision(10)<<res<<endl;
}