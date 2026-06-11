#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

struct edge{ll to, cost;};
vector<vector<edge>> G(100005);
vector<ll> Djikstra(ll n, ll start){
    //小さい順に取り出す
    priority_queue<pll, vector<pll>, greater<pll>> que;

    vector<ll> min_dist(n+1);
    fill(ALL(min_dist), LINF); 

    min_dist[start] = 0;
    //firstは距離、secondは頂点番号
    que.push(make_pair(0, start));

    while(!que.empty()){
        pll top = que.top();
        que.pop();

        ll v = top.second;

        //既により短い経路があるのなら更新しない
        if(min_dist[v] < top.first)continue;

        rep(i, G[v].size()){
            edge e = G[v][i];
            //最短慶経路を更新できる場合、更新し格納
            if(min_dist[e.to] > min_dist[v] + e.cost){
                min_dist[e.to] = min_dist[v] + e.cost;
                que.push(make_pair(min_dist[e.to], e.to));
            }
        }
    }

    return min_dist;
}

int main(){
    ll n;
    cin >> n;

    rep(i, n-1){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        G[u].push_back(edge{v, w});
        G[v].push_back(edge{u, w});
    }

    vector<ll> dist = Djikstra(n, 0);
    rep(i, n){
        if(dist[i] & 1)cout << 1 << endl;
        else cout << 0 << endl;
    }
}