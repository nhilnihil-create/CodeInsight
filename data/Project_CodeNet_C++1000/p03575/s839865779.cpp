#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m, a, b;
    cin >> n >> m;
    vector<pair<ll,ll>> edges;
    vector<vector<ll>> paths(n+1);
    for (ll i=0; i<m; i++) {
        cin >> a >> b;
        paths[a].push_back(b);
        paths[b].push_back(a);
        edges.push_back(make_pair(a,b));
    }
    ll res = m;
    queue<ll> moves;
    for (auto i : edges) {
        while (moves.size()>0) moves.pop();
        vector<bool> visited(n+1,0);
        ll x = i.first;
        ll y = i.second;
        for (auto j : paths[x]) if (j!=y) moves.push(j);
        visited[x] = true;
        while (moves.size()>0) {
            ll curr = moves.front();
            moves.pop();
            if (visited[curr]) continue;
            visited[curr] = true;
            if (curr==y) {
                res--;
                break;
            }
            for (auto j : paths[curr]) {
                moves.push(j);
            }
        }
    }
    cout << res;
    return 0;
}