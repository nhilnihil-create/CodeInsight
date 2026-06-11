#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    ll n, m, d;
    cin >> n >> m >> d;
    double ans = 0;
    if (d == 0) ans += 1.0 / n;
    else {
        ans += 2.0 * double(n - d) / double(n * n);
    }
    ans *= double(m - 1);
    printf("%.9f\n", ans);
}