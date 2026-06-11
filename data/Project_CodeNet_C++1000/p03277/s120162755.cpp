#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

/*
    1-indexed であることに注意 !!
*/
template <typename T>
struct BIT {
    int n;
    vector<T> dat;

    BIT(int n) : n(n), dat(n + 1, 0) {}

    T sum(int a) {
        T res = 0;
        for (int i = a; i > 0; i -= (i & (-i))) res += dat[i];
        return res;
    }

    T sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }

    void add(int k, T x) {
        if (k == 0) return;
        for (int i = k; i <= n; i += (i & (-i))) dat[i] += x;
    }

    /*
        a[0] + a[1] + ... + a[res] >= x
    */
    int lower_bound(T x) {
        if (x <= 0) return T(0);
        int res = 0, k = 1;
        while (k < n) k <<= 1;
        for (; k > 0; k >>= 1) {
            if (res + k <= n && dat[res + k] < x) {
                x -= dat[res + k];
                res += k;
            }
        }
        return res + 1;
    }
};

signed main() {
    int n;
    cin >> n;
    ll a[n];
    rep(i, n) {
        cin >> a[i];
    }
    auto isOK = [&](ll x) {
        int sum[n + 1] = {};
        rep(i, n) {
            sum[i] = (a[i] >= x ? 1 : -1);
        }
        rep(i, n) {
            sum[i + 1] += sum[i];
        }
        ll cnt = 0;
        BIT<int> bit(2 * n);
        bit.add(n + 0, 1);
        rep(i, n) {
            cnt += bit.sum(n + sum[i]);
            bit.add(n + sum[i], 1);
        }
        return cnt >= ((ll)n * (n + 1) / 2 + 1) / 2;
    };
    ll ok = 0, ng = INF + 1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}