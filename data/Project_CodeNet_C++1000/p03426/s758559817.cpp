#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, d;
    cin >> n >> m >> d;
    vector<pair<int, int>> a(100010);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            a[x] = {i, j};
        }
    }
    vector<vector<int>> g(d + 1);
    for (int i = 1; i <= d; i++) {
        g[i].push_back(0);
        g[i].push_back(0);
        for (int j = i + d; j <= 100000; j += d) {
            g[i].push_back(abs(a[j].first - a[j - d].first) + 
                abs(a[j].second - a[j - d].second) + g[i].back()
            );
        }
    }
    
    
    int q;
    cin >> q;
    while (q-- > 0) {
        int l, r;
        cin >> l >> r;
        int i = l % d;
        if (i == 0) {
            i = d;
            cout << g[i][r / d] - g[i][l / d] << '\n';
        } else {
            cout << g[i][r / d + 1] - g[i][l / d + 1] << '\n';
        }
    }
}