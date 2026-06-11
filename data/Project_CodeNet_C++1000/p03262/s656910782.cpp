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
ll LCM(ll x, ll y);

int main() {
    ll N, X, tmp, ans;
    cin >> N >> X;

    vector<ll>dif(N);

    ans = pow(10, 9);

    rep(i, N) {
        cin >> tmp;
        dif[i] = abs(X - tmp);
        ans = min(ans, dif[i]);
    }

    rep(i, N) {
        ans = min(ans, LCM(ans, dif[i]));
    }

    cout << ans;

    return 0;
}


ll LCM(ll x, ll y) {
    ll a, b, r, gcd, lcm;
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