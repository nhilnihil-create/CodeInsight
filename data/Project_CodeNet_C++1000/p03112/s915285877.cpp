#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    ll a,b,q;
    cin >> a >> b >> q;
    ll max = mod*mod;
    vector<ll> s(a),t(b),sm(a),tm(b);
    for(ll i = 0; i < a; i++){
        cin >> s[i];
        sm[a-i-1] = -s[i];
    }
    for(ll i = 0; i < b; i++){
        cin >> t[i];
        tm[b-i-1] = -t[i];
    }
    vector<ll> ans;
    for(ll i = 0; i < q; i++){
        ll x;
        cin >> x;
        auto sf = lower_bound(s.begin(),s.end(),x);
        auto sb = lower_bound(sm.begin(),sm.end(),-x);
        auto tf = lower_bound(t.begin(),t.end(),x);
        auto tb = lower_bound(tm.begin(),tm.end(),-x);
        ll can1 = max,can2 = max,can3 = max,can4 = max;
        if(sf != s.end() && tf != t.end()) can1 = min(abs(x-*sf),abs(x-*tf))+abs(*sf-*tf);
        if(sf != s.end() && tb != tm.end()) can2 = min(abs(x-*sf),abs(x+*tb))+abs(*sf+*tb);
        if(sb != sm.end() && tf != t.end()) can3 = min(abs(x+*sb),abs(x-*tf))+abs(-*sb-*tf);
        if(sb != sm.end() && tb != tm.end()) can4 = min(abs(x+*sb),abs(x+*tb))+abs(-*sb+*tb);
        ans.push_back(min(can1,min(can2,min(can3,can4))));
    }
    for(auto p: ans) cout << p << endl;
    return 0;
}