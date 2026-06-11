#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll n; cin >> n;
    vector<ll> t(n + 1, 0), x(n + 1, 0), y(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
    
    bool can = true;
    vector<ll> dt(n), dist(n);
    for (int i = 0; i < n; i++) {
        dt[i] = t[i + 1] - t[i];
        dist[i] = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
        if (!(dist[i] <= dt[i] && dt[i] % 2 == dist[i] % 2)) {
            can = false;
        }
    }

    if (can)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;

}