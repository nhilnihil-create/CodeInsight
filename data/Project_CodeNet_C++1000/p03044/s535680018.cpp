#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long
#define umap unordered_map
using graph = vector<vector<int>>;
using graph2 = vector<vector<pair<int, int>>>;
#define oorret true //std::out_of_rangeが返された時
#define oor(x) [&](){try{x;} catch(const std::out_of_range& oor){return oorret;} return x;}()
ll mod(ll x, ll y){if(x>=0||x%y==0) return x%y;return y+x%y;} //mod including minus
ll dv0(ll x, ll y){if(x>=0||x%y==0)return x/y;return x/y-1;} //rnd down
ll dv1(ll x, ll y){if(x%y==0) return dv0(x,y);return dv0(x,y)+1;} //rnd up

// 深さ優先探索

void dfs(vector<bool> &seen, graph2 &G, vector<int> &d, int a) {
    seen[a]= true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for(auto next_v: G[a]){
        if(seen[next_v.first]==true)continue;
        d[next_v.first]=(d[a]+next_v.second)%2;
        dfs(seen, G, d, next_v.first);
    }
}

int main() {
    int N;
    cin>>N;
    int u, v, w;
    graph2 G(N);
    rep(i, N-1){
        cin>>u>>v>>w;
        G[u-1].push_back(make_pair(v-1, w%2));
        G[v-1].push_back(make_pair(u-1, w%2));
    }
    vector<bool> seen(N);
    rep(i, N){
        seen[i]=false;
    }
    vector<int> d(N);
    d[0]=0;
    dfs(seen, G, d, 0);
    rep(i, N){
        cout<<d[i]<<endl;
    }
}