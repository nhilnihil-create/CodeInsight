#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

ll GCD(ll x, ll y);

int main() {

    ll N;

    cin >> N;

    ll x;
    cin >> x;
    ll ans = x;

    rep(i, N - 1) {
        cin >> x;
        ans = GCD(ans, x);
        if (ans == 1) {
            break;
        }
    }

    cout << ans;

    return 0;
}
ll GCD(ll x, ll y) {
    ll a, b, r, gcd;
    a = max(x, y);
    b = min(x, y);
    r = 1;
    while (r != 0) {
        r = a % b;
        if (r == 0) {
            gcd = b;
        }
        a = b;
        b = r;
    }
    return gcd;
}