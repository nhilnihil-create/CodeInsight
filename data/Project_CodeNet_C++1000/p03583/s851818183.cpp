#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P  = pair<int, int>;
int main() {
    ll N;
    cin >> N;
    for (ll h = 1; h <= 3500; ++h)
        for (ll n = 1; n <= 3500; ++n) {
            ll w_d = 4 * h * n - N * (n + h);
            ll w_n = N * h * n;
            if (w_d <= 0 || w_n % w_d != 0) continue;
            ll w   = w_n / w_d;
            if (w > 3500 || w < 1) continue;
            ll n_n = 4 * h * n * w;
            ll n_d = h * n + n * w + w * h;
            if (n_n % n_d != 0) continue;
            if (N == n_n / n_d)
                return cout << h << " " << n << " " << w << endl, 0;
        }
}