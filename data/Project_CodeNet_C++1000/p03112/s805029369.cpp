#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const ll INF=2e15;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false); 

    int a,b,q;
    cin >> a >> b >> q;
    vector<ll> s(a+2),t(b+2);
    s[0]=-INF;
    t[0]=-INF;
    s[a+1]=INF;
    t[b+1]=INF;
    rep(i,a) cin >> s[i+1];
    rep(i,b) cin >> t[i+1];
    rep(i,q) {
        ll x;
        cin >> x;
        int ss=lower_bound(s.begin(),s.end(),x)-s.begin();
        int tt=lower_bound(t.begin(),t.end(),x)-t.begin();
        ll ans1=(s[ss]>t[tt])?s[ss]-x:t[tt]-x;
        ll ans2=(s[ss-1]<t[tt-1])?x-s[ss-1]:x-t[tt-1];
        ll mins=(s[ss]-x<x-s[ss-1])?s[ss]-x:x-s[ss-1];
        ll mint=(t[tt]-x<x-t[tt-1])?t[tt]-x:x-t[tt-1];
        ll ans3=(mins<mint)?2*mins+mint:2*mint+mins;
        ll ans=(ans1<ans2)?ans1:ans2;
        ans=(ans<ans3)?ans:ans3;
        cout << ans << endl;
    }
    return 0;
}
