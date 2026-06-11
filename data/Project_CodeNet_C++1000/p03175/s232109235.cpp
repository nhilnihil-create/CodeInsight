#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<ll>>;

ll dp[100100][2];//dp[v][color]
Graph G;

ll rec(int v, int color, int parent){
    if(dp[v][color]!=-1) return dp[v][color];
    ll res = 1;
    for(auto nv : G[v]){
        ll tmp = 0;
        if(nv != parent){
            if(!color) (tmp += rec(nv,1,v)) %= MOD;
            (tmp += rec(nv,0,v)) %= MOD;
            tmp %= MOD;
            if(tmp!=0) (res *= tmp) %= MOD;
        }
    }
    res %= MOD;
    return dp[v][color] = res;
}

int main(){
    int N; cin>>N;
    G.resize(N);
    rep(i,N-1){
        int x,y; cin>>x>>y;
        x--;y--;
        G[x].push_back(y); G[y].push_back(x);
    }
    rep(i,100100)rep(j,2)dp[i][j] = -1;
    ll res = rec(0,0,-1);
    res += rec(0,1,-1);
    res %= MOD;
    cout<<res<<endl;
}

