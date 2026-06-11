#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (long i = long(s); i < long(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long;
using ull = unsigned long long;
using namespace std;

long mmin(long a, long b){
    if(a < b) return a;
    else return b;
}
long mmax(long a, long b){
    if(a < b) return b;
    else return a;
}

const ll inf = 100100100100;

int main(){
    ll a, b, q; cin >> a >> b >> q;
    vector<ll> s(a); rep(i,a) cin >> s[i];
    vector<ll> t(b); rep(i,b) cin >> t[i];

    rep(i,q){
        ll x; cin >> x;
        ll ss = lower_bound(all(s),x)-s.begin();
        ll tt = lower_bound(all(t),x)-t.begin();

        ll aa = s[ss]-x; if(ss == a) aa = inf;
        ll ab = t[tt]-x; if(tt == b) ab = inf;
        ll a1 = mmax(aa,ab);
        ll ba = x-s[ss-1]; if(ss == 0) ba = inf;
        ll bb = x-t[tt-1]; if(tt == 0) bb = inf;
        ll a2 = mmax(ba,bb);
        ll cc = 2*aa + bb;
        ll cd = 2*ab + ba;
        ll a3 = mmin(cc,cd);
        ll dc = 2*bb + aa;
        ll dd = 2*ba + ab;
        ll a4 = mmin(dc,dd);
        ll ans = mmin(mmin(a1,a2),mmin(a3,a4));
        cout << ans << endl;
    }
}