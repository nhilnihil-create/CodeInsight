#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
constexpr int INF = (1<<29);
using ll = long long;
using pii = pair<int,int>;

struct edge{
    int to,cost;
    edge(int to, int cost) : to(to), cost(cost) {}
};

int main(){
    int k; cin >> k;
    vector<vector<edge>> g(k);

    for(int i=1;i<k;i++){
        g[i].emplace_back((i+1)%k,1);
        g[i].emplace_back((i*10)%k,0);
    }

    vector<int> d(k,INF);
    priority_queue<pii,vector<pii>,greater<pii>> que;
    que.push(pii(1,1));
    d[1] = 1;
    while(!que.empty()){
        pii now = que.top(); que.pop();
        int v = now.second;
        if(d[v] < now.first) continue;
        for(edge& e : g[v]){
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(pii(d[e.to],e.to));
            }
        }
    }

    cout << d[0] << endl;
}
