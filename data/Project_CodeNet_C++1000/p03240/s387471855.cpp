#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> X(n), Y(n), H(n);
    for (ll i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i] >>H[i];
    }

    ll cx = -1, cy = -1, h = -1;

    for (ll i = 0; i <= 100; ++i) {
        bool gok = false;
        for (ll j = 0; j <= 100; ++j) {
            ll tmpH;
            bool ok = true;
            bool firstOne = true;

            for (ll k = 0; k < n; ++k) {
                if (H[k] == 0) continue;
                if (firstOne) {
                    tmpH = H[k] + abs(X[k]-i) + abs(Y[k]-j);
                    firstOne = false;
                } else {
                    if (tmpH != H[k] + abs(X[k]-i) + abs(Y[k]-j)) {
                        ok = false;
                        break;
                    }
                }
            }

            if (!ok) continue;

            for (ll k = 0; k < n; ++k) {
                if (H[k] > 0) continue;
                if (tmpH > abs(X[k]-i) + abs(Y[k]-j)) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cx = i;
                cy = j;
                h = tmpH;
                gok = true;
            }
        }
        if (gok) break;
    }

    cout << cx << " " << cy << " " << h << endl;
}

