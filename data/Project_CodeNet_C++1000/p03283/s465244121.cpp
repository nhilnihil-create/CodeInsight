#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m, q, a, b;
    cin >> n >> m >> q;
    vector<ll> row(n+1,0);
    vector<vector<ll>> arr(n+1,row);
    for (ll i=0; i<m; i++) {
        cin >> a >> b;
        arr[a][b]++;
    }
    for (ll i=0; i<=n; i++) {
        ll csum = 0;
        for (ll j=0; j<=n; j++) {
            csum+=arr[i][j];
            arr[i][j] = csum;
        }
    }
    for (ll i=0; i<q; i++) {
        ll res = 0;
        cin >> a >> b;
        for (ll j=a; j<=b; j++) {
            res+=arr[j][b];
        }
        cout << res << endl;
    }
    return 0;
}