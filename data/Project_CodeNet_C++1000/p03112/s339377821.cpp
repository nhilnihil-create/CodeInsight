#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a,b,q;
    cin >> a >> b >> q;
    ll s[a];
    for(ll i=0;i<a;i++) cin >> s[i];
    ll t[b];
    for(ll i=0;i<b;i++) cin >> t[i];
    for(ll i=0;i<q;i++){
        ll x;
        cin >> x;
        ll res=1e12;
        ll memos;
        memos=lower_bound(s,s+a,x)-s;
        ll memot;
        memot=lower_bound(t,t+b,x)-t;
        for(ll j=0;j<2;j++){
            for(ll k=0;k<2;k++){
                res=min(res,abs(s[memos-j]-t[memot-k])+min(abs(s[memos-j]-x),abs(t[memot-k]-x)));
            }
        }
        cout << res << endl;
    }
}
