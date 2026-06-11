#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<ll>>;

ll dp[100100][2];//dp[v][color]
vector<ll> dist;

ll rec(int v, int color, const Graph &G){
    if(dp[v][color]!=-1) return dp[v][color];
    ll res = 1;
    for(auto nv : G[v]){
        ll tmp = 0;
        if(dist[nv]==dist[v]+1){
            if(!color) (tmp += rec(nv,1,G)) %= MOD;
            (tmp += rec(nv,0,G)) %= MOD;
            tmp %= MOD;
            if(tmp!=0) (res *= tmp) %= MOD;
        }
    }
    // if(res==1){
    //     //端点
    //     return dp[v][color] = 1;
    // }
    res %= MOD;
    return dp[v][color] = res;
}

int main(){
    int N; cin>>N;
    dist.resize(N,-1);
    Graph G(N);
    rep(i,N-1){
        int x,y; cin>>x>>y;
        x--;y--;
        G[x].push_back(y); G[y].push_back(x);
    }
    queue<int> Q;
    dist[0] = 0;
    Q.push(0);
    while(!Q.empty()){
        ll v = Q.front(); Q.pop();
        for(auto nv: G[v]){
            if(dist[nv]!=-1) continue;
            dist[nv] = dist[v] + 1;
            Q.push(nv);
        }
    }
    rep(i,100100)rep(j,2)dp[i][j] = -1;
    ll res = rec(0,0,G);
    res += rec(0,1,G);
    res %= MOD;
    cout<<res<<endl;
}

