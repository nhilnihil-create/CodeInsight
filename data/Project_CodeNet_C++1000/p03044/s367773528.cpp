#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

//#define DEBUG(fmt, ...)
#define DEBUG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll N;

    cin >> N;

    vector<vector<pair<ll,ll>>> nodes(N);

    REP(i,N-1){
       ll u, v, w;
       cin >> u >> v >> w;
       nodes[u-1].push_back(make_pair(v-1,w));
       nodes[v-1].push_back(make_pair(u-1,w));
    }

    vector<ll> colors(N,0);
    vector<bool> visited(N, false);
    ll color = 0;
    queue<ll> q;
    q.push(0);
    colors[0] = color;
    visited[0] = true;
    while(!q.empty()){
       ll cur = q.front();
       q.pop();
       ll cur_color = colors[cur];
       for( auto& child : nodes[cur]){
          ll next = child.first;
          ll w = child.second;
          if( visited[next] == false ){
             if( w % 2 ==  0 ){
                 colors[next] = cur_color;
             }else{
                 colors[next] = (cur_color+1)%2;
             }
             q.push(next);
             visited[next] = true;
          }
       }
    }

    REP(i, N){ cout << colors[i] << endl; }
}
