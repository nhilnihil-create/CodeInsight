#include <bits/stdc++.h>
#define M_PI           3.14159265358979323846  /* pi */
using namespace std;
using  ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll>t(n + 1, 0);
    vector<ll>x(n + 1, 0);
    vector<ll>y(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        cin >> t.at(i) >> x.at(i) >> y.at(i);
    }
    ll tnow;
    ll xynow;
    bool result = true;

    for (ll i = 1; i <= n; i++) {
        tnow = (t.at(i) - t.at(i - 1));
        xynow = abs(x.at(i) - x.at(i - 1)) + abs(y.at(i) - (y.at(i - 1)));

        if (tnow < xynow)result = false;
        if (xynow % 2 != tnow % 2)result = false;
    }
    if (result == true)cout << "Yes" << endl;
    else cout << "No" << endl;
}