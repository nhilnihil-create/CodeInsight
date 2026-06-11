#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
// const ll MOD = 998244353;
const double PI=3.14159265358979323846;

int main() {
    int x, y; cin >> x >> y;
    if(x%y == 0) cout << -1 << endl;
    else cout << x << endl;
    return 0;
}
