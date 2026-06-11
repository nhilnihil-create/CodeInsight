#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;

vector<ll> c;
vector<ll> ab;

ll cnt(ll n) {
    ll ret = 0;
    auto r = lower_bound(all(ab),n-c[0]);
    ret += ab.end()-r;
    rep2(i,1,c.size()) {
        ll l = c[i];
        while(true) {
            if(r == ab.begin()) break;
            if(*(r-1) >= n-l) r--;
            else break;
        }
        ret += ab.end()-r;
    }
    return ret;
}

ll solve(ll k,ll l = 0,ll r = 30000000001) {
    if(r-l == 1) return l;
    ll mid = (l+r)/2;
    ll n = cnt(mid);
    if(n >= k) return solve(k,mid,r);
    else return solve(k,l,mid);
}

int main() {
    ll x,y,z,k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x),b(y);
    vector<ll> oc(z),oab;
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> oc[i];
    rep(i,x) rep(j,y) oab.pb(a[i]+b[j]);
    sort(all(oab));
    for(int i = max(0,int(oab.size()-k)); i < oab.size(); i++) ab.pb(oab[i]);
    sort(all(oc));
    for(int i = max(0,int(oc.size()-k)); i < oc.size(); i++) c.pb(oc[i]);
    rep2(i,1,k+1) cout << solve(i) << endl;
}