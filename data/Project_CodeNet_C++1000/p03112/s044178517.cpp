#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int a, b, q;
    cin >> a >> b >> q;
    int s[a], t[b];
    rep(i, 0, a) cin >> s[i];
    rep(i, 0, b) cin >> t[i];
    rep(i, 0, q) {
        int x;
        cin >> x;
        auto itr_mns = lower_bound(s, s + a, x);
        auto itr_mnt = lower_bound(t, t + b, x);
        auto itr_mxs = lower_bound(s, s + a, x);
        auto itr_mxt = lower_bound(t, t + b, x);
        int mns = *itr_mns;
        int mnt = *itr_mnt;
        int mxs = *itr_mxs;
        int mxt = *itr_mxt;
        if (itr_mns == s) {
            mns = -inf;
        } else if (itr_mxs == s + a) {
            itr_mns--;
            mns = *itr_mns;
            mxs = inf;
        } else {
            itr_mns--;
            mns = *itr_mns;
        }
        if (itr_mnt == t) {
            mnt = -inf;
        } else if (itr_mxt == t + b) {
            itr_mnt--;
            mnt = *itr_mnt;
            mxt = inf;
        } else {
            itr_mnt--;
            mnt = *itr_mnt;
        }
        // cout << mns << " " << mxs << "\n";
        // cout << mnt << " " << mxt << "\n";
        int ans = min({abs(x + mxt - 2 * mns), abs(x + mxs - 2 * mnt), abs(2 * mxs - x - mnt), abs(2 * mxt - x - mns),
                       abs(x - min(mns, mnt)), abs(max(mxs, mxt) - x)});
        // cout << abs(x + mxt - 2 * mns) << " " << abs(x + mxs - 2 * mnt) << " " << abs(2 * mxs - x - mnt) << " "
        //  << abs(2 * mxt - x - mns) << " " << abs(x - min(mns, mnt)) << " " << abs(max(mxs, mxt) - x) << "\n";
        cout << ans << "\n";
    }
}