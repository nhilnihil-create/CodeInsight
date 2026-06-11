#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

ll K;
vector<ll> dist(100001, LLONG_MAX); //distance[i]は始点(start)から頂点iへの最短距離が入る

void Dijkstra(){ //start = 始点
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(make_pair(1, 1));
    while(!que.empty()){
        ll d, t;
        tie(d, t) = que.top(); que.pop();
        if(dist[t] <= d) continue;
        dist[t] = d;
        if(dist[(t + 1) % K] > d + 1) que.push(make_pair(d + 1, (t + 1) % K));
        if(dist[(t * 10) % K] > d) que.push(make_pair(d, (t * 10) % K));
    }
}

int main(void){
    
    scanf("%lld", &K);
    Dijkstra();
    printf("%lld\n", dist[0]);
    
    return 0;
}
