#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n, m, k, cnt, s;
int mask[10];
int p[10];
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> s;
            mask[s - 1] |= 1 << i;
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < (1 << n); ++i) {
        int msk = 0;
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                msk ^= mask[j];
            }
        }
        for (int j = 0; j < m; ++j) {
            if (((msk & (1 << j)) >> j) != p[j]) {
                ok = false;
                break;
            }
        }
        if (ok)
            ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
