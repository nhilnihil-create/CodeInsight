#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

template<typename T>
using reversed_priority_queue = \
    std::priority_queue<T, std::vector<T>, std::greater<T> >;

ll INF = 1ll << 60;

signed main() {
    ll K;
    cin>>K;
    vector<vector<PLL>> edges(K); // edges[k]: first: コスト second: 次の頂点
    rep(i,0,K){
        // 頂点i の次は、コスト1で(i+1)%K 
        // あるいは、    コスト0で(i*10)%K
        edges[i].push_back({1, (i+1)%K});
        edges[i].push_back({0, (i*10)%K});
    }

    vector<ll> dist(K, INF);
    reversed_priority_queue<PLL> q;
    q.push({1,1}); // 整数1は、最小で1回の加算で作れる
    while(!q.empty()){
        ll d = q.top().first;
        ll id = q.top().second;
        q.pop();
        if (d < dist[id]) {
            dist[id] = d;
            for(auto e: edges[id]){
                q.push({e.first + d, e.second});
            }
        }
    }
    cout<<dist[0]<<endl;
    return 0;
}
