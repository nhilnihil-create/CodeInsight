#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, m;
    cin >> n >> m;
    vector < pair < pair < int, int >, int > > inp(n);
    set < int > ts[m + 1];
    for (int i = 0; i < n; ++i) {
        cin >> inp[i].first.first >> inp[i].first.second >> inp[i].second;
        ts[inp[i].second].insert(inp[i].first.second);
    }
    vector < pair < int, int > > events(2 * n);
    for (int i = 0; i < n; ++i) {
        int s = inp[i].first.first, t = inp[i].first.second, c = inp[i].second;
        if (ts[c].find(s) == ts[c].end())
            events[i] = make_pair(s - 1, 1);
        else
            events[i] = make_pair(s, 1);
        events[n + i] = make_pair(t, -1);
    }
    sort(events.begin(), events.end());
    int ans = 0, b = 0;
    for (auto event: events) {
        b += event.second;
        ans = max(ans, b);
    }
    cout << ans << '\n';
}
