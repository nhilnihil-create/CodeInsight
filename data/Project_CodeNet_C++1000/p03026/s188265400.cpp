#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    vector<int> c(n);
    ll m = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        m += c[i];
    }
    sort(c.begin(), c.end());
    m -= c[c.size() - 1];
    cout << m << endl;
    int start;
    for (int i = 1; i <= n; i++) {
        if ((int)tree[i].size() == 1) {
            start = i;
            break;
        }
    }
    vector<int> d(n);
    d[start - 1] = c[0];
    queue<pair<int, int>> q;
    q.emplace(pair<int, int>{start, 0});
    while (!q.empty()) {
        int cur = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto v : tree[cur]) {
            if (v == parent) {
                continue;
            }
            q.push(pair<int, int>{v, cur});
            d[v - 1] = c[c.size() - 1];
            c.pop_back();
        }
    }
    for (auto e : d) {
        cout << e << " ";
    }
    return 0;
}
