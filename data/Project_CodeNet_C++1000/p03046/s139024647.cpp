#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) ((x).begin(), (x).end())
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int m, k;
    cin >> m >> k;
    if((1 << m) <= k || m == 1 && k == 1) {
        cout << -1 << endl;
        return 0;
    }
    if(m == 1) {
        cout << "0 0 1 1" << endl;
        return 0;
    }
    V<int> x;
    rep(i, 1 << m) if(i != k) {
        x.push_back(i);
        cout << i << " ";
    }
    cout << k << " ";
    FORR(i, x.size()) cout << x[i] << " ";
    cout << k << endl;

    return 0;
}