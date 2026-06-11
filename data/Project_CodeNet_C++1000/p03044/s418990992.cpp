#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 10e9+7;
ll mod2 = 998244353;

struct edge {int to, cost;};
vector<edge> G[100010];
vector<int> ans(100010,-1);

int dfs(int v,int d){
    if (ans[v]!=-1) return 0;
    ans[v] = d%2;
    for (auto e:G[v]){
        dfs(e.to,e.cost+d);
    }
}

int main(){
    int n;cin>>n;
    rep(i,0,n-1){
        int u,v,w;cin>>u>>v>>w;
        edge x = {u-1,w%2};
        edge y = {v-1,w%2};
        G[u-1].push_back(y);
        G[v-1].push_back(x);
    }
    dfs(0,0);
    rep(i,0,n){
        cout<<ans[i]<<endl;
    }
}