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

//更新順序が非自明
int dp[100100];
int rec(int now,Graph const & G){
    if(dp[now]!=-1) return dp[now];
    int res = 0;
    for(auto nv:G[now]){
        res = max(res,rec(nv,G)+1);
    }
    return dp[now] = res;
}

int main(){
    int N,M; cin>>N>>M;
    Graph G(N);
    rep(i,M){
        int x,y; cin>>x>>y;
        x--;
        y--;
        G[x].push_back(y);
    }
    rep(i,100100)dp[i] = -1;

    int res = 0;
    rep(i,N)res = max(res,rec(i,G));
    cout<<res<<endl;
}