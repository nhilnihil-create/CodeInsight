#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b);
    rep(i, 0, a) cin >> s[i];
    rep(i, 0, b) cin >> t[i];
    s.push_back(-1e18);
    s.push_back(1e18);
    t.push_back(-1e18);
    t.push_back(1e18);
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    rep(i, 0, q) {
        ll x;
        cin >> x;
        auto itr_s = lower_bound(s.begin(), s.end(), x);
        auto itr_t = lower_bound(t.begin(), t.end(), x);
        ll tmp1 = 1e18, tmp2 = 1e18, tmp3 = 1e18, tmp4 = 1e18;
        ll tmp5 = max(*itr_s, *itr_t) - x;
        ll tmp6 = x - min(*(itr_s - 1), *(itr_t - 1));
        // s-, t+
        {
            ll dt = abs(*itr_t - x);
            ll ds = abs(*(itr_s - 1) - x);
            tmp1 = 2*min(dt, ds) + max(dt, ds);
        }
        // s-, t-
        {
            ll dt = abs(*(itr_t - 1) - x);
            ll ds = abs(*(itr_s - 1) - x);
            tmp2 = 2*min(dt, ds) + max(dt, ds);
        }
        // s+, t+
        {
            ll dt = abs(*itr_t - x);
            ll ds = abs(*itr_s - x);
            tmp3 = 2*min(dt, ds) + max(dt, ds);
        }
        // s+, t-
        {
            ll dt = abs(*(itr_t - 1) - x);
            ll ds = abs(*itr_s - x);
            tmp4 = 2*min(dt, ds) + max(dt, ds);
        }
        cout << min({tmp1, tmp2, tmp3, tmp4, tmp5, tmp6}) << endl;
    }
    return 0;
}