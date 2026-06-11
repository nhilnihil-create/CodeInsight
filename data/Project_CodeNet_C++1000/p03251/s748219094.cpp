#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    int x[n], y[m];
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];

    bool ok = false;
    for (int z = X + 1; z <= Y; z++) {
        bool war = false;
        rep(i, n) if (x[i] >= z) war = true;
        rep(i, m) if (y[i] < z) war = true;
        if (!war) {
            ok = true;
            break;
        }
    }

    if (ok)
        cout << "No War" << endl;
    else
        cout << "War" << endl;
    return 0;
}
