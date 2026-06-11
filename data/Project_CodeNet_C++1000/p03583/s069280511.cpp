#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
using namespace std;

int main() {
    ll N;
    cin >> N;

    for (ll i = 1; i <= 3500; ++i) {
        for (ll j = i; j <= 3500; ++j) {
            if ((4 * i * j - N * (i + j)) == 0)
                continue;
            if ((N * i * j) % (4 * i * j - N * (i + j)) != 0)
                continue;

            ll k = (N * i * j) / (4 * i * j - N * (i + j));
            if (k >= 0) {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }

    return 0;
}