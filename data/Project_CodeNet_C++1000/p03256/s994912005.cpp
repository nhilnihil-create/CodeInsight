#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    vector<vector<int>> cnt(n, vector<int>(2));
    vector<bool> removed(n);
    queue<int> que;
    for(int v = 0; v < n; ++v) {
        for(auto to : g[v]) {
            cnt[v][s[to] == 'B'] += 1;
        }
        if(cnt[v][0] == 0 || cnt[v][1] == 0) {
            que.push(v);
            removed[v] = true;
        }
    }
    while(!que.empty()) {
        const int v = que.front();
        que.pop();
        for(auto to : g[v]) {
            if(removed[to]) continue;
            cnt[to][s[v] == 'B'] -= 1;
            if(cnt[to][s[v] == 'B'] == 0) {
                que.push(to);
                removed[to] = true;
            }
        }
    }

    if(find(begin(removed), end(removed), false) != end(removed)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}