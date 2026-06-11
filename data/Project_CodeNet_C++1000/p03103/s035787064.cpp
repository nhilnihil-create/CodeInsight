#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

#define INF 1e9
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int main() {
    ll n, m;
    ll ans = 0;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll> (2));
    rep(i, n) {
        rep(j, 2) {
            cin >> a.at(i).at(j);
        }
    }
    sort(a.begin(), a.end());
    rep(i, n) {
        if (a.at(i).at(1) <= m) {
            m -= a.at(i).at(1);
            ans += a.at(i).at(0) * a.at(i).at(1);
        }
        else {
            ans += a.at(i).at(0) * m;
            goto last;
        }
    }
    last:
    cout << ans << endl;
}