#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main(){
    ll n,m;
    std::cin >> n>>m;
    std::vector<vector<pair<ll,ll>>> graph(n);
    for (int i = 0; i < m; i++) {
        ll l,r,d;
        std::cin >> l>>r>>d;
        l--;
        r--;
        
        graph[l].push_back({r,d});
        graph[r].push_back({l,-d});
    }
    const ll INF = 1e14;
    vector<ll> dist(n,INF);
    std::queue<pair<ll,ll>> que;
    for (int i = 0; i < n; i++) {
        if(dist[i] != INF){
            continue;
        }
        dist[i] = 0;
        que.push({i,0});
        while(!que.empty()){
            auto q = que.front();
            que.pop();

            for (auto e : graph[q.first]) {
                if(dist[e.first] == INF){
                    dist[e.first] = dist[q.first] + e.second;
                    que.push({e.first,dist[e.first]});
                }else{
                    if(dist[e.first] != dist[q.first] + e.second){
                        std::cout << "No" << std::endl;
                        return 0;
                    }
                }
            }
        }
    }
    std::cout << "Yes" << std::endl;
}
