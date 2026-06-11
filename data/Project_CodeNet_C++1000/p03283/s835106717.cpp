#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> trains(n + 1);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        trains[l].push_back(r);
    }
    for (int i = 0; i < n; i++)
        sort(trains[i].begin(), trains[i].end());
    for (int i = 0; i < q; i++) {
        int cnt = 0;
        int p, q;
        cin >> p >> q;
        for (int k = p; k <= q; k++)
            cnt += upper_bound(trains[k].begin(), trains[k].end(), q) - trains[k].begin();
        cout << cnt << endl;
    }
    return 0;
}
