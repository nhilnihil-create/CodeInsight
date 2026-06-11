#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dfs(ll x, bool a, bool b, bool c, ll n) {
    if (x > n) return 0;

    ll res = 0;

    if (x <= n && x != 0 && a && b && c) res++;

    res += dfs(10*x+3, true, b, c, n);
    res += dfs(10*x+5, a, true, c, n);
    res += dfs(10*x+7, a, b, true, n);

    return res;
}

int main() {
    ll n;
    cin >> n;

    ll ans = dfs(0LL, false, false, false, n);

    cout << ans << endl;
}
