#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll n;
    cin >> n;
    for (ll h = 1; h <= 3500; h++) {
        for (ll w = 1; w <= 3500; w++) {
            ll numerator = n * h * w;
            ll denominator = 4 * h * w - n * w - n * h;
            if (denominator > 0 && numerator % denominator == 0) {
                ll ans = numerator / denominator;
                cout << h << " ";
                cout << ans << " ";
                cout << w << endl;
                return 0;
            }
        }
    }
}