#include <bits/stdc++.h>
using namespace std;
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef vector<vector<vector<ll>>> mat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
// constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

// for (int i = 0; i <= n; ++i)
int main() {
    int n;
    int res = 0;
    // int vv,cc;
    cin >> n;
    vector<long long> v(n), c(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    for (int i = 0; i < n; i++) {
        if (v[i] - c[i] >= 0) {
            res += v[i] - c[i];
        }
    }
    cout << res << endl;
    return 0;
}
