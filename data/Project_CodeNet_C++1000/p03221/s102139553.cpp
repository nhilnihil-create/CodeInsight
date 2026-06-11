#include <bits/stdc++.h>
using namespace std;

string num (int x) {
    string res = to_string(x);
    while (int(res.size()) < 6)
        res = "0" + res;
    return res;
}

signed main () {
    int n, m;
    cin >> n >> m;
    vector < vector < pair < int, int > > > region(n + 1);
    for (int i = 0; i < m; ++i) {
        int p, y;
        cin >> p >> y;
        region[p].push_back(make_pair(y, i));
    }
    for (int i = 0; i <= n; ++i)
        sort(region[i].begin(), region[i].end());
    vector < string > ans(m);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < int(region[i].size()); ++j) 
            ans[region[i][j].second] = num(i) + num(j + 1);
    }
    for (string s: ans)
        cout << s << '\n';
}
