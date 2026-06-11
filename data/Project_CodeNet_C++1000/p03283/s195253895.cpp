#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int f(const vector<int>& v, int n) {
    if (v.size() == 0 || v[0] > n) return 0;
    int b = 0, e = v.size() - 1;
    while (b < e) {
        int m = (b + e) / 2 + 1;
        if (v[m] > n) {
            e = m - 1;
        } else {
            b = m;
        }
    }
    return b + 1;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> vp(m, make_pair(0, 0));
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &vp[i].first, &vp[i].second);
    }
    sort(vp.begin(), vp.end());
    vector<vector<int>> v(n + 1, vector<int>(0));
    for (int i = 0; i < m; i++) {
        v[vp[i].first].push_back(vp[i].second);
    }
    vector<vector<int>> res(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int c = 0;
            for (int k = i; k <= j; k++) {
                c += f(v[k], j);
            }
            res[i][j] = c;
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", res[l][r]);
    }
}
