#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A+2), t(B+2);
    s[0] = -1e18; s[A+1] = 1e18;
    t[0] = -1e18; t[B+1] = 1e18;
    rep(i, 1, A+1) cin >> s[i];
    rep(i, 1, B+1) cin >> t[i];
    rep(q, 0, Q){
        ll x; cin >> x;
        auto jin = lower_bound(s.begin(), s.end(), x);
        auto ter = lower_bound(t.begin(), t.end(), x);
        ll ans = max(*jin, *ter) - x;
        ans = min(ans, x - min(*(jin-1), *(ter-1)));
        ans = min(ans, 2 * min(x - *(jin-1), *ter - x) + max(x - *(jin-1), *ter - x));
        ans = min(ans, 2 * min(x - *(ter-1), *jin - x) + max(x - *(ter-1), *jin - x));
        cout << ans << endl;
    }
    return 0;
}