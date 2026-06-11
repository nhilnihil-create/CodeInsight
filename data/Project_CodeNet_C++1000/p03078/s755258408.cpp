#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<lint, int>;
using vec = vector<lint>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vec a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];

    sort(all(a), greater<lint>());
    sort(all(b), greater<lint>());
    sort(all(c), greater<lint>());

    vec d;
    rep(i, min(x, k)) rep(j, min(y, k)) {
        d.push_back(a[i] + b[j]);
    }
    sort(all(d), greater<lint>());

    vec e;
    rep(i, min(k, (int)d.size())) rep(j, min(z, k)) {
        e.push_back(d[i] + c[j]);
    }
    sort(all(e), greater<lint>());

    rep(i, k) {
        cout << e[i] << endl;
    }

    return 0;
}