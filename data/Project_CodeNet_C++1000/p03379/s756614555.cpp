#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll n; cin >> n;

    vector<ll> x(n),y;
    for (ll i = 0; i < n; i++) cin >> x[i];
    y = x;
    sort(y.begin(), y.end());

    int medianLeft = y[n / 2 - 1];
    int medianRight = y[n / 2];

    for (int i = 0; i < n; i++) {
        if (x[i] <= medianLeft) {
            cout << medianRight << endl;
        }
        else {
            cout << medianLeft << endl;
        }
    }

    return 0;
}