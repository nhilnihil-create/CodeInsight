#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using st = string;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) { x = max(x, y); }
#define chmin(x, y) { x = min(x, y); }

int main() {
    int n;
    cin >> n;
    ll ans;
    vector<ll> l(n + 1);
    l.at(0) = 2;
    l.at(1) = 1;
    mrep(i, 2, n + 1) l.at(i) = l.at(i - 1) + l.at(i - 2);
    ans = l.at(n);
    cout << ans << endl;
    return 0;
}