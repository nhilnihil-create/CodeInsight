#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
vector<ll> ret;
vector<ll> divisor(ll n) {
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    return ret;
}

/*証明*/
/*
N=(商)*m+(mで割った余り)
ここで、条件を満たす場合(商)=N%m
また、(mで割った余り)は当然N%m
ゆえに、N=(N%m)*m+(N%m)=(N%m)*(m+1)
N%m=kとおいて
N=k*(m+1)
*/
int main() {
    ll n;
    cin >> n;

    ll ans = 0;
    divisor(n);
    rep(i, ret.size()) {
        if (ret[i] == 1) continue;
        if (n / (ret[i] - 1) == n % (ret[i] - 1)) ans += (ret[i] - 1);
    }
    /*
        ll ans2 = 0;
        rep(i, n) {
            if (i == 0) continue;
            if (n / i == n % i) ans2 += i;
        }
    */
    cout << ans << "\n";
    //    cout << ans2 << "\n";
    return 0;
}