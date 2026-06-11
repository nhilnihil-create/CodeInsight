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
    int N,K; cin>>N>>K;
    vector<int> a(N);
    rep(i,N)cin>>a[i];
    vector<bool> dp(K+10,false);
    rep1(k,K){
        auto iter = upper_bound(a.begin(),a.end(),k) - a.begin();
        rep(n,(ll)iter){
            dp[k] =  dp[k] || !dp[k-a[n]];
        }
    }
    if(dp[K])cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}