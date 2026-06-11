#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()    // 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend() // 降順ソート 例：sort(DESC(vec));
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i < n; i++)
#define REP(i, vec) for (auto i = vec.begin(); i != vec.end(); ++i)

const int       mod = 1000000007;
const int       inf = (1 << 21);
const long long INF = 1LL << 60;

using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vii = vector<pair<int, int>>;
using vll = vector<pair<ll, ll>>;

template<class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline T GCD(T a, T b) {
    return b ? GCD(b, a % b) : a;
}
template<class T>
inline T LCM(T a, T b) {
    return (a + (b - 1)) / b;
}

int round_int(int a, int b) {
    return (a + (b - 1)) / b;
}

constexpr array<int, 9> dx = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
constexpr array<int, 9> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };

// ──────────────────────────────────────────────────────────────────

int main() {
    int n;
    ll k;
    cin >> n >> k;

    vl a(n);
    rep(i, n) cin >> a[i];

    ll res = 0;
    for (int d = 60; d >= -1; d--) {
        if (d != -1 && !(k & (1LL << d))) continue;

        ll tmp = 0;
        for (int e = 60; e >= 0; e--) {
            ll mask = 1LL << e;
            int num = 0;
            rep(i, n) if (a[i] & mask) ++num;

            if (e > d) {
                if (k & mask) tmp += mask * (n - num);
                else tmp += mask * num;
            }
            else if (e == d) {
                tmp += mask * num;
            }
            else {
                tmp += mask * max(num, n - num);
            }
        }
        res = max(res, tmp);
    }
    cout << res << endl;
}