#include <bits/stdc++.h>
#define rep(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define repr(i, n, m) for (int i = (int)(n) - 1; i >= (int)(m); i--)
using namespace std;
using ll = int64_t;
const int MOD = 1000000007; // 10^9+7
// https://atcoder.jp/contests/agc032/tasks/agc032_b
int main() {
    int n; cin >> n;

    // if (n == 3) {
    //     cout << 2 << endl;
    //     cout << 1 << " " << 3 << endl;
    //     cout << 2 << " " << 3 << endl;
    //     return
    // }

    ll edge;
    if (n % 2 == 0) edge = n * (n - 2) / 2;
    else edge = (n - 1) * (n - 1) / 2;
    cout << edge << endl;

    int m = (n % 2 == 0) ? n : n - 1;
    for (int from = 1; from < m; from++)
    {
        for (int to = from + 1; to <= m; to++)
        {
            if (to != m - from + 1) {
                cout << from << " " << to << endl;
            }
        }
    }

    if (n % 2 == 1) {
        for (int to = 1; to < n; to++)
        {
            cout << n << " " << to << endl;
        }
    }
}
