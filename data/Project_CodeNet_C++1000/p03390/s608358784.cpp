#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i) 
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

constexpr static int MOD = 1000000000 + 7;
constexpr static int inf = INT_MAX / 2;
constexpr static llong INF = LLONG_MAX / 2;
constexpr static int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    rep(i, q) {
        llong a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 2 * (a - 1) << endl;
            continue;
        }
        llong lim = a * b - 1, left = -1, right = 1LL<<31;
        while (right - left > 1) {
            llong mid = (left + right) / 2;
            llong mul = (mid + 1) / 2 * (mid + 1 - (mid + 1) / 2);
            if (mul > lim) right = mid;
            else left = mid;
        }
        cout << left - 1 << endl;
    }

    return 0;
}