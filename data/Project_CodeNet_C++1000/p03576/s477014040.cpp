#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 1000000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int n, kmin;
    cin >> n >> kmin;
    vector<ll> x(n), y(n);
    vector<pair<ll, ll>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        p[i] = make_pair(x[i], y[i]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll ans = infl * 4LL;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = i + 1; k < n; ++k) {
                for (int l = j + 1; l < n; ++l) {
                    int cnt = 0;
                    ll xmin = x[i], xmax = x[k], ymin = y[j], ymax = y[l];
                    for (int m = 0; m < n; ++m) {
                        cnt += (int)(xmin <= p[m].first && p[m].first <= xmax && ymin <= p[m].second && p[m].second <= ymax);
                    }

                    if (cnt >= kmin)
                        ans = min(ans, (xmax - xmin) * (ymax - ymin));
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}