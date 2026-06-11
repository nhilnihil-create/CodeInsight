#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll H, W, ans=0, tmp=0, C[10]={0}; 
map<ll, ll> MP;
vector<pair<ll, ll>> adj[10];

void dijkstra(ll start) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> PQ;
    ll color[10];
    ll d[10];
    for(int i=0;i<10;i++) {
        d[i] = 1000000000;
        color[i] = 0;
    }
    d[start] = 0;
    PQ.push(make_pair(d[start], start));
    color[start] = 1;
    while(!PQ.empty()) {
        pair<ll, ll> p = PQ.top();
        PQ.pop();
        ll u = p.second;
        color[u] = 2;
        if(d[u]<p.first) continue;
        for(int j=0;j<adj[u].size();j++) {
            ll v = adj[u][j].first;
            if(color[v]==2) continue;
            if(d[v]>d[u]+adj[u][j].second) {
                d[v]=d[u]+adj[u][j].second;
                PQ.push(make_pair(d[v], v));
                color[v]=1;
            }
        }
    }
    C[start] = d[1];
}

signed main(){
    cin >> H >> W;
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            ll num;
            cin >> num;
            adj[i].push_back(make_pair(j, num));
        }
    }
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            ll num;
            cin >> num;
            if(num==-1) num = 1;
            MP[num]++;
        }
    }
    for(int i=0;i<10;i++) {
        dijkstra(i);
    }
    for(map<ll, ll>::iterator itr=MP.begin();itr!=MP.end();itr++) {
        pair<ll, ll> p = *itr;
        ans += C[p.first]*p.second;
    }
    cout << ans << endl;
    return 0;
}