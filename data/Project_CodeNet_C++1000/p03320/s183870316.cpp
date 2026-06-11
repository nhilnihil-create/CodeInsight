#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
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

ll dsum(ll n) {
    ll r = 0;
    while(n) {
        r += n % 10;
        n /= 10;
    }
    return r;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll k;
    cin >> k;
    ll x = 1, p = 1;
    while(k--) {
        cout << x << endl;
        ll x1 = x + p;
        ll x2 = x + p * 10;
        if(x1 * dsum(x2) <= x2 * dsum(x1))
            x = x1;
        else {
            x = x2;
            p *= 10;
        }
    }

    return 0;
}