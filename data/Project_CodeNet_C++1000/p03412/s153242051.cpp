#include <bits/stdc++.h>

using namespace std;

#define i64 int64_t
#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i)
#define fore(i,a) for (auto &i : a)
#define repr(i, n) for (int i = n; i >= 0; --i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int mod = 1000000000 + 7;
const static int inf = INT_MAX / 2;
const static llong INF = LLONG_MAX / 2;
const static double eps = 1e-10;
const static int dx[] = {1, 0, -1, 0};
const static int dy[] = {0, 1, 0, -1};

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0;}

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    i64 n;
    cin >> n;
    vector<i64> A(n), B(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];

    i64 ans = 0;
    for (int digit = 28; digit >= 0; --digit) {
        i64 cnt = 0;
        for (int i = 0; i < n; ++i) {
            A[i] %= (1LL << digit + 1);
            B[i] %= (1LL << digit + 1); 
        }
        sort(all(B));

        for (int i = 0; i < n; ++i) {
            cnt += lower_bound(all(B), 2LL * (1LL << digit) - A[i]) - lower_bound(all(B), (1LL << digit) - A[i]);
            cnt += lower_bound(all(B), 4LL * (1LL << digit) - A[i]) - lower_bound(all(B), 3LL * (1LL << digit) - A[i]);
        }

        if (cnt % 2) ans += (1LL << digit);
    }

    cout << ans << endl;

    return 0;
}