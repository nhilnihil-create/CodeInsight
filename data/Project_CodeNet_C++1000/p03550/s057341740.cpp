#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    ll n, z, w;
    cin >> n >> z >> w;
    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << abs(a[0] - w) << endl;
        return 0;
    }
    ll ret = 0;
    chmax(ret, abs(a[n - 2] - a[n - 1]));
    chmax(ret, abs(a[n - 1] - w));
    cout << ret << "\n";
    return 0;
}