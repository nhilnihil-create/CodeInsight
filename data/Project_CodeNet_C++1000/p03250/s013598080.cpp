#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define nl '\n'
#define f(i, n) for (int i = 0; i < n; ++i)

using namespace std;
void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = max({a + 10 * b + c, 10 * a + b + c, 10 * c + a + b});
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}