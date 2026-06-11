#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll X;
    cin >> X;
    for (ll h = 1; h <= 3500; h++) {
        for (ll n = 1; n <= 3500; n++) {
            ll waro = 4 * h * n - X * h - X * n;
            if (waro != 0 && (X * n * h) % waro == 0) {
                ll w = (X * n * h) / waro;
                if (w > 0) {
                    cout << h << " " << n << " " << w << endl;
                    return 0;
                }
            }
        }
    }
}