#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, m;
    cin >> n >> m;
    vector < vector < int > > open(n + 1);
    vector < set < int > > close(n + 1); // sort of scanline
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        open[a].push_back(b);
        close[b].insert(a);
    }
    int ans = 0;
    vector < pair < int, int > > cur;
    for (int i = 0; i <= n; ++i) {
        if (!close[i].empty()) {
            for (auto ab: cur) {
                int a = ab.first, b = ab.second;
                close[b].erase(a);
            }
            cur.clear();
            ++ans;
        }
        for (int b: open[i]) 
            cur.push_back(make_pair(i, b));
    }
    cout << ans << '\n';
}
