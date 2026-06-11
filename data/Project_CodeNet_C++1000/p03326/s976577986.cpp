#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n, m;
    cin >> n >> m;
    ll a[n+10][3];
    ll maxn = -(1LL << 60);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < 8; i++) {
        vector<ll> vec;
        for (int j = 1; j <= n; j++) {
            ll s = 0;
            for (int k = 0; k < 3; k++) {
                if ((i / (1 << k) % 2 == 0)) {
                    s += a[j][k];
                } else {
                    s -= a[j][k];
                }
            }
            vec.push_back(s);
        }
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        ll ans = 0;
        for (int j = 0; j < m; j++) {
            ans += vec[j];
        }
        maxn = max(maxn, ans);
    }

    cout << maxn << endl;

    return 0;
}