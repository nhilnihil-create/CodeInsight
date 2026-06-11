#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)
template <typename T>
T _gcd(T a, T b) {
    return b ? _gcd(b, a % b) : a;
}

template <typename T>
T _gcd_vector(vector<T> a) {
    T res = a[0];
    for (T i = 1; i < a.size(); i++) {
        res = _gcd(a[i], res);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    ll ans = _gcd_vector(a);

    cout << ans << endl;
}