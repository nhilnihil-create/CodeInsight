#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ipair;
typedef pair<ll, ll> llpair;
    
/*
    Author: Koushik Sahu
    Created: 11 Sep 2020 15:31:14
*/

int n, m, e1, e2;
vvint g;

vint topoSort(){
    vint ans;
    queue<int> q;
    int indeg[n];
    fill_n(indeg, n, 0);
    for(int i=0; i<n; i++){
        for(int j: g[i]) indeg[j]++;
    }
    for(int i=0; i<n; i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int v: g[u]){
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>n>>m;
    g.resize(n);
    for(int i=0; i<m; i++){
        cin>>e1>>e2;
        e1--, e2--;
        g[e1].push_back(e2);
    }
    vint topo_order = topoSort();
    int dist[n];
    fill_n(dist, n, INT_MIN);
    for(int i=0; i<topo_order.size(); i++){
        int u = topo_order[i];
        if(dist[u]==INT_MIN) dist[u] = 0;
        for(int v: g[u]){
            if(dist[v]<dist[u]+1){
                dist[v] = dist[u] + 1;
            }
        }
    }
    cout<<*max_element(dist, dist+n)<<"\n";
    return 0;
}