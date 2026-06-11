#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 998244353
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    int N,M; cin>>N>>M;
    Graph G(N);
    vector<int> deg(N,0); //入り次数
    vector<int> dp(N,0); //sourceからの最長距離
    rep(i,M){
        int x,y; cin>>x>>y;
        x--; y--;
        G[x].push_back(y);
        deg[y]++;
    }

    queue<int> que;
    rep(v,N) if(deg[v]==0) que.push(v);

    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto nv : G[v]){
            deg[nv]--;
            if(deg[nv]==0){
                que.push(nv);
                chmax(dp[nv],dp[v]+1);
            }
        }
    }

    int res = 0;
    rep(v,N) chmax(res,dp[v]);
    cout<<res<<endl;
}