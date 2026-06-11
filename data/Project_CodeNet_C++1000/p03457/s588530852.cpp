#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

ll dis(ll x1, ll y1, ll x2, ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> t(n), x(n), y(n);
    rep(i, n){
        cin >> t[i] >> x[i] >> y[i];
    }

    ll pre_t = 0;
    ll pre_x = 0;
    ll pre_y = 0;
    rep(i, n){
        ll dt = t[i] - pre_t;
        ll d = dis(pre_x, pre_y, x[i], y[i]);
        if (dt < d){
            cout << "No" << endl;
            return 0;
        }
        if ((dt - d) % 2 == 1){
            cout << "No" << endl;
            return 0;
        }
        pre_t = t[i];
        pre_x = x[i];
        pre_y = y[i];
    }

    cout << "Yes" << endl;

    return 0;
}
