#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    int a,b,q;
    cin >> a >> b >> q;
    ve<ll> s(a), t(b);
    rep(i,a) cin >> s[i];
    rep(i,b) cin >> t[i];
    rep(Q,q){
        ll x;
        cin >> x;
        auto ita = lower_bound(s.begin(), s.end(), x);
        auto itb = lower_bound(t.begin(), t.end(), x);
        ll es,et,ws,wt;
        if(ita == s.begin()) es = -2e15;
        else es = *prev(ita);
        if(ita == s.end()) ws = 2e15;
        else ws = *ita;
        if(itb == t.begin()) et = -2e15;
        else et = *prev(itb);
        if(itb == t.end()) wt = 2e15;
        else wt = *itb;
        ll ans = min(max(x-es,x-et),max(ws-x,wt-x));
        ans = min(ans,(x-es)+wt-es);
        ans = min(ans,(x-et)+ws-et);
        ans = min(ans,ws-x+ws-et);
        ans = min(ans,wt-x+wt-es);
        cout << ans << endl;
    }
    return 0;
}