#include<bits/stdc++.h>
using namespace std;

// template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
// template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 998244353
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    int N; cin>>N;
    vector<ll> dp(3,0);
    rep(i,N){
        ll a,b,c; cin>>a>>b>>c;
        a += max(dp[1],dp[2]);
        b += max(dp[0],dp[2]);
        c += max(dp[0],dp[1]);
        dp[0] = a;
        dp[1] = b;
        dp[2] = c;
    }
    cout<<max({dp[0],dp[1],dp[2]})<<endl;
}