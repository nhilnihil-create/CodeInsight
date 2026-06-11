#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<deque>
#include<map>
using namespace std;
typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> xy(n);
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++)
    {
        int xx, yy; cin >> xx >> yy;
        x[i] = xx;
        y[i] = yy;
        xy[i] = make_pair(xx, yy);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll ans = 4*1e18;
    for (int left = 0; left < n; left++) {
        for (int right = left+1; right < n; right++) {
            for (int bottom = 0; bottom < n; bottom++) {
                for (int upper = bottom+1; upper < n; upper++){
                    int l = x[left], r = x[right];
                    int b = y[bottom], u = y[upper];
                    int tmp = 0;
                    for (int i = 0; i < n; i++) {
                        if (xy[i].first >= l && xy[i].first <= r && xy[i].second >= b && xy[i].second <= u)
                            tmp++;
                    }
                    if (tmp >= k) {
                        ans = min(ans, (ll)(r-l)*(ll)(u-b));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}