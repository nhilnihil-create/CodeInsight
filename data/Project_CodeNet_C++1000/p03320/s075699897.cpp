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
constexpr static llong INF = 1LL<<31;
constexpr static int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

llong s(llong x) {
    llong re = 0;
    while (x > 0) {
        re += x % 10;
        x /= 10;
    }
    return re;
}

bool cmp(llong x, llong y) {
    return x * s(y) <= y * s(x);
}

void solve(int K) {
    llong d = 1, cur = 0;
    rep(i, K) {
        llong x = cur + d, y = cur + d * 10;
        if (cmp(x, y)) {
            cur = x;
        } else {
            cur = y;
            d *= 10;
        }
        cout << cur << endl;
    }
}

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    llong k;
    cin >> k;
    solve(k);

    return 0;
}