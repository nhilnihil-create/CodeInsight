#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}



int main() {
    int a,b,q;
    cin >> a >> b >> q;
    vector<ll>s(a+2),t(b+2);
    s[0] = -1e18;t[0] = -1e18;
    s[a+1] = 1e18;t[b+1] = 1e18;
    for(int i = 1;i<=a;i++) cin >> s[i];
    for(int i = 1;i<=b;i++) cin >> t[i];
    rep(i,q) {
        ll x;
        cin >> x;
        ll ans = 1e18;
        ll sa,sb;
        ll ta,tb;
        rep(i,2) {
            if(i==0) { //右側の神社
                sa = lower_bound(s.begin(),s.end(),x)-s.begin();
                //神社から右に行くか左にいくか
                rep(j,2) {
                    if(j==0) {
                        ta = lower_bound(t.begin(),t.end(),s[sa])-t.begin();
                        ll tmp = abs(x-s[sa]) + abs(s[sa]-t[ta]);
                        
                        ans = min(ans,tmp);
                    }
                    if(j==1) {
                        tb = ta-1;
                        ll tmp = abs(x-s[sa]) + abs(s[sa]-t[tb]);
                        
                        ans = min(ans,tmp);
                    }
                }
            }
            if(i==1) { //最初に左側の神社
                sb = sa-1;
                //神社から右に行くか左にいくか
                rep(j,2) {
                    if(j==0) { //右側の寺
                        ta = lower_bound(t.begin(),t.end(),s[sb])-t.begin();
                        ll tmp = abs(x-s[sb]) + abs(s[sb]-t[ta]);
                        
                        ans = min(ans,tmp);
                    }
                    if(j==1) { //左側の寺
                        tb = ta-1;
                        ll tmp = abs(x-s[sb]) + abs(s[sb]-t[tb]);
                        
                        ans = min(ans,tmp);
                    }
                }
            }
        }
        //最初に寺に行く
        rep(i,2) {
            if(i==0) {
                ta = lower_bound(t.begin(),t.end(),x)-t.begin();
                rep(j,2) {
                    if(j==0) {
                        sa = lower_bound(s.begin(),s.end(),t[ta])-s.begin();
                        ll tmp = abs(x-t[ta])+abs(t[ta]-s[sa]);
                        
                        ans = min(ans,tmp);
                    }
                    if(j==1) {
                        sb = sa-1;
                        ll tmp = abs(x-t[ta])+abs(t[ta]-s[sb]);
                        
                        ans = min(ans,tmp);
                    }
                }
            }
            if(i==1) {
                tb = ta-1;
                rep(j,2) {
                    if(j==0) {
                        sa = lower_bound(s.begin(),s.end(),t[tb])-s.begin();
                        ll tmp = abs(x-t[tb])+abs(t[tb]-s[sa]);
                        
                        ans = min(ans,tmp);
                    }
                    if(j==1) {
                        sb = sa-1;
                        ll tmp = abs(x-t[tb])+abs(t[tb]-s[sb]);
                        
                        ans = min(ans,tmp);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}