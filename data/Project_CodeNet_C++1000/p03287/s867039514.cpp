#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;

signed main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    int s[n + 1] = {};
    rep (i, 0, n) {
        cin >> a[i];
        s[i + 1] = (s[i] + a[i]) % m;
    }
    map<int, int> mp;
    rep (i, 0, n + 1) { mp[s[i]]++; }
    int ans = 0;
    for (auto p : mp) {
        ans += p.second * (p.second - 1) / 2;
    }
    cout << ans << "\n";
}