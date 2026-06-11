#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b), x(q);
    rep(i, 0, a) cin >> s[i];
    rep(i, 0, b) cin >> t[i];
    rep(i, 0, q) cin >> x[i];
    rep(i, 0, q){
        auto pos = x[i];
        auto sitr = lower_bound(s.begin(), s.end(), pos);
        auto titr = lower_bound(t.begin(), t.end(), pos);
        ll s_l, s_r, t_l, t_r;
        if(sitr == s.begin()) {
            s_r = *sitr - pos;
            s_l = 1e18;
        }else if(sitr == s.end()){
            s_r = 1e18;
            s_l = pos - (*(sitr-1));
        }else{
            s_r = *sitr - pos;
            s_l = pos - *(sitr - 1);
        }
        if(titr == t.begin()) {
            t_r = *titr - pos;
            t_l = 1e18;
        }else if(titr == t.end()){
            t_r = 1e18;
            t_l = pos - (*(titr-1));
        }else{
            t_r = *titr - pos;
            t_l = pos - *(titr-1);
        }
        ll c1 = max(s_l, t_l);
        ll c2 = max(s_r, t_r);
        ll c3 = 2 * min(s_l, t_r) + max(s_l, t_r);
        ll c4 = 2 * min(s_r, t_l) + max(s_r, t_l);
        cout << min({c1, c2, c3, c4}) << endl;
    }
    return 0;
}