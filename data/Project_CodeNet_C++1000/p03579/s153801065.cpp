#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 510000;
const int MOD = 1000000007;

using Graph = vector<vector<ll> >;

int main() {
    // 頂点数と辺数
    ll N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //二分グラフの判定
    bool is_bipartite = true;
    vector<ll> dist(N, -1);
    queue<ll> que;
    for (ll v = 0; v < N; ++v) {
        if (dist[v] != -1) continue; // v が探索済みならスルー
        dist[v] = 0, que.push(v);
        while (!que.empty()) {
            ll v = que.front(); que.pop();
            for (auto nv : G[v]) {
                if (dist[nv] == -1) {
                    dist[nv] = dist[v] + 1;
                    que.push(nv);
                } else {
                    // 整合性を確認する
                    if (dist[v] == dist[nv]) is_bipartite = false;
                }
            }
        }
    }


    if(!is_bipartite){
      ll ans = N*(N-1)/2 - M;
      cout<<ans<<endl;
    }
    else{
      ll ans = 0;
      rep(i,N){
        if(dist[i] %2 == 0) ans++;
      }
      ans = ans*(N-ans) - M;
      cout<<ans<<endl;
    }
}
