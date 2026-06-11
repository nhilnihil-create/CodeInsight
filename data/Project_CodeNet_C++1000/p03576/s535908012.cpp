#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> xy(n);
    vector<int> x(n), y(n);
    ll ans = __LONG_LONG_MAX__;
    
    rep(i, n) {
        cin >> x[i] >> y[i];
        xy[i].first = x[i];
        xy[i].second = y[i];
    }
    
    sort(all(x));
    sort(all(y));
    
    rep(lx, n) {
        reps(rx, lx, n) {
            rep(ly, n) {
                reps(ry, ly, n) {
                    int cnt = 0;
                    
                    rep(i, n) {
                        if (
                            (xy[i].first >= x[lx]) &&
                            (xy[i].first <= x[rx]) &&
                            (xy[i].second >= y[ly]) &&
                            (xy[i].second <= y[ry])
                        )
                        {
                            cnt++;
                        }
                    }
                    
                    if (cnt >= k) {
                        ans = min(ans, (ll)(x[rx] - x[lx]) * (y[ry] - y[ly]));
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
