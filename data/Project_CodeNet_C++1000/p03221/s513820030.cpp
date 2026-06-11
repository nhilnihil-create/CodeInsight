#include <bits/stdc++.h>
using namespace std;


void solve () {
    int n, m;
    cin >> n >> m;
    unordered_map <int , vector<int>> mp;
    vector<pair <int, int>> a(m);
    for (int i = 0; i < m; i++) {
        int p, y;
        cin >> p >> y;
        mp[p].push_back(y);
        a[i].first = p;
        a[i].second = y;
    }
    for (auto t = mp.begin(); t != mp.end(); t++) {
        sort((*t).second.begin(), (*t).second.end());
    }
    for (int i = 0; i < m; i++) {
        int p = a[i].first;
        int y = a[i].second;
        printf("%06d", p);
        int l = lower_bound(mp[p].begin(), mp[p].end(), y) - mp[p].begin();
        printf("%06d\n", l + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
