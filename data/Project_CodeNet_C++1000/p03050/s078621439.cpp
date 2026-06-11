#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin >> n;
    ll ans = 0;
    for (ll i = 1; i * i < n; i++) {
        if ((n - i) % i == 0 && i < (n - i) / i) ans += (n - i) / i;
    }
    cout << ans << endl;
    return 0;
}