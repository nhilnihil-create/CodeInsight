#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;


int main() {
    int n, m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(3, 0));
    rep(i, n) cin >> a[i][0] >> a[i][1] >> a[i][2];

    ll res = 0;
    for (int bit = 0; bit < (1<<3); ++bit) {
        vector<ll> b;
        rep(i, n) {
            ll tmp = 0;
            rep(j, 3) {
                if (bit & (1<<j)) tmp += a[i][j];
                else tmp -= a[i][j];
            }
            b.push_back(tmp);
        }
        sort(all(b), greater<ll>());
        ll sum = 0;
        rep(i, m) sum += b[i];
        res = max(res, sum);
    }
    cout << res << endl;
}