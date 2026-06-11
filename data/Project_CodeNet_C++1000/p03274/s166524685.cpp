#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> x, y;
    y.push_back(0);
    for (int i=0;i<n;++i) {
        ll a;
        cin >> a;
        if (a < 0) x.push_back(-a);
        else y.push_back(a);
    }

    x.push_back(0);//番兵(なんでこれが必要なのかは不明)
    sort(x.begin(), x.end());
    int ms = min(k, (ll)y.size()-1);//kと正の数の個数のmin
    ll ans = 1e16;
    for (int i = ms; i >= 0; i--) {
        if (k - i >= x.size()) break;//正の数と負の数の和の個数の和がkを上回ったらダメ
        ans = min(ans, 2 * y[i] + x[k - i]);
        ans = min(ans, 2 * x[k - i] + y[i]);
    }
    cout << ans << endl;
    return 0;
}
