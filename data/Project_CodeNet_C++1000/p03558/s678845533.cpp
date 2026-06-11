#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const int INF = (1LL<<31)-1;

int main(){
    ll K; cin >> K;
    vector<vector<P> > G(K);
    for(int i=0;i<K-1;i++){
        G[i].push_back({10*i%K,0});
        G[i].push_back({(i+1),1});
    }
    G[K-1].push_back({10*(K-1)%K,0});
    G[K-1].push_back({0,1});
    vector<int> dist(K,INF);

    deque<P> que; que.push_back({1,1});
    
    while(!que.empty()){
        P cur = que.front();
        que.pop_front();
        int v = cur.first;
        int cost = cur.second;
        if(dist[v]!=INF) continue;
        dist[v] = cost;

        for(auto nxt : G[v]){
            int nv = nxt.first;
            int c = nxt.second;
            if(dist[nv]==INF){
                if(c){
                    que.push_back({nv,cost+1});
                }else{
                    que.push_front({nv,cost});
                }
            }
        }
    }
    cout << dist[0] << endl;
}