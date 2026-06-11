#include <queue>
#include <set>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<set<int> > adj(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].insert(y); adj[y].insert(x);
    }
    bool rem[n] = {};
    int cnt[n][2] = {};
    for (int i = 0; i < n; i++) for (int j : adj[i]) cnt[i][s[j] - 'A']++;
    for (int i = 0; i < n; i++) {
        if (rem[i] || (cnt[i][0] > 0 && cnt[i][1] > 0)) continue;
        queue<int> q;
        q.push(i); rem[i] = true;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u : adj[v]) {
                if(!rem[u] && --cnt[u][s[v]-'A'] == 0) { rem[u] = true; q.push(u); }
            }
        }
    }
    for (int i = 0; i < n; i++) if (!rem[i]) { cout << "Yes\n"; return 0; }
    cout << "No\n";
}
