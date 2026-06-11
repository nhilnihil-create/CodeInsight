#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

int main() {
    int a,b,q;
    cin >> a >> b >> q;
    vector<ll> s(a),t(b);
    rep(i,a) cin >> s[i];
    rep(i,b) cin >> t[i];
    rep(i,q) {
        ll ans;
        ll x;
        cin >> x;
        auto sit = lower_bound(all(s),x);
        auto tit = lower_bound(all(t),x);
        if(sit == s.begin()) {
            if(tit == t.begin()) {
                ans = max(*sit,*tit)-x;
            } else if(tit == t.end()){
                tit--;
                ans = *sit-*tit+min(*sit-x,x-*tit);
            } else {
                auto titb = tit-1;
                ans = min(*sit-*titb+min(*sit-x,x-*titb),max(*sit,*tit)-x);
            }
        } else if(sit == s.end()) {
            sit--;
            if(tit == t.begin()) {
                ans = *tit-*sit+min(*tit-x,x-*sit);
            } else if(tit == t.end()) {
                tit--;
                ans = x-min(*sit,*tit);
            } else {
                auto titb = tit-1;
                ans = min(*tit-*sit+min(*tit-x,x-*sit),x-min(*sit,*titb));
            }
        } else {
            auto sitb = sit-1;
            if(tit == t.begin()) {
                ans = min(max(*sit,*tit)-x,*tit-*sitb+min(*tit-x,x-*sitb));
            } else if(tit == t.end()) {
                tit--;
                ans = min(x-min(*tit,*sitb),*sit-*tit+min(*sit-x,x-*tit));
            } else {
                auto titb = tit-1;
                ans = min(max(*sit,*tit)-x,*tit-*sitb+min(*tit-x,x-*sitb));
                chmin(ans,min(x-min(*titb,*sitb),*sit-*titb+min(*sit-x,x-*titb)));
            }
        }
        cout << ans << endl;
    }
}
