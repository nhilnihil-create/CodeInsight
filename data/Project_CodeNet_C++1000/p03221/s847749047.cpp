#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<set<pair<int, int>>> p_y_i(n);
    for (int i=0; i<m; ++i) {
        int p, y; cin >> p >> y;
        p--;
        p_y_i[p].insert(make_pair(y, i));
    }
    vector<pair<int, int>> cities(m);
    for (int p=0; p<n; ++p) {
        if (p_y_i[p].empty()) continue;

        int cnt = 1;
        for (auto i: p_y_i[p]) {
            cities[i.second] = make_pair(p + 1, cnt);
            cnt++;
        }
    }
    for (auto i: cities) {
        printf("%06d%06d\n", i.first, i.second);
    }
}