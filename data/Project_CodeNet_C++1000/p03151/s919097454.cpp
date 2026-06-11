#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), x(n);
    rep(i, n) cin >> a[i];

    ll sum = 0, cnt = 0;
    rep(i, n) {
        cin >> b[i];
        if (a[i] >= b[i])
            x.push_back(a[i] - b[i]);
        else {
            sum += b[i] - a[i];
            ++cnt;
        }
    }

    sort(x.begin(), x.end(), greater<ll>());

    rep(i, x.size()) {
        if (sum <= 0)
            break;
        sum -= x[i];
        ++cnt;
    }

    if (sum > 0)
        cout << -1 << endl;
    else
        cout << cnt << endl;

    return 0;
}