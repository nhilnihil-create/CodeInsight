#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans = 1;
    if(b - a <= 2) {
        ans += k; 
    }
    else {
        ans += a - 1;
        if((k - a + 1) % 2 == 1) {
            ans++;
            k--;
        }
        ans += (k - a + 1) / 2 * (b - a);
    }
    cout << ans << endl;
    return 0;
}