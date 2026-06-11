#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int n;
    cin >> n;
    bool vis[n + 5] = {};
    vector<vector<pair<ll, ll>>> v;
    v.resize(n + 5);
    for(int i = 0; i < n - 1; i++){
        ll x, y, c;
        cin >> x >> y >> c;
        v[x].push_back({y, c});
        v[y].push_back({x, c});
    }
    ll dist[n + 5] = {};
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    vis[1] = true;
    while(q.size()){
        ll node = q.front();
        q.pop();
        for(int i = 0; i < v[node].size(); i++){
            if(vis[v[node][i].first]) continue;
            vis[v[node][i].first] = true;
            dist[v[node][i].first] = (dist[node] + v[node][i].second) % 2;
            q.push(v[node][i].first);
        }
    }
    for(int i = 1; i <= n; i++)
        cout << dist[i] << endl;
    return 0;
}