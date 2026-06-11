#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    int n, K;
    cin >> n >> K;
    vector<pair<ll, ll>> xy(n);
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> xy[i].first >> xy[i].second;
        x[i] = xy[i].first;
        y[i] = xy[i].second;
    }
    sort(all(xy));
    sort(all(x));
    sort(all(y));
    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = 0; k < n; k++) {
                for(int l = k + 1; l < n; l++) {
                    int count = 0;
                    for(int p = 0; p < n; p++) {
                        if(xy[p].first >= x[i] && xy[p].first <= x[j] &&
                           xy[p].second >= y[k] && xy[p].second <= y[l]) {
                            count++;
                        }
                    }
                    if(count >= K) {
                        ans = min(ans, (x[j] - x[i]) * (y[l] - y[k]));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}