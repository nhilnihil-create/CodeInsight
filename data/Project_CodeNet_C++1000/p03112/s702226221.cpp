#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>S
#define PP pair<P,P>
using namespace std;

int main(){
    int a,b,q; cin >> a >> b >> q;
    vector<ll> s(a),t(b);
    rep(i,a) cin >> s[i];
    rep(i,b) cin >> t[i];

    rep(i,q){
        ll x; cin >> x;
        ll ans=400000000000;
        auto ids=lower_bound(all(s),x);
        auto idt=lower_bound(all(t),x);
        ll sl,sr,tl,tr;
        sl=sr=tl=tr=-1;
        if(ids!=s.begin()) sl=s[ids-s.begin()-1];
        if(idt!=t.begin()) tl=t[idt-t.begin()-1];
        if(ids!=s.end()) sr=s[ids-s.begin()];
        if(idt!=t.end()) tr=t[idt-t.begin()];
        //cout << sl << ' ' << sr << ' ' << tl << ' ' << tr << endl;

        if(sl!=-1) sl=x-sl;
        if(sr!=-1) sr=sr-x;
        if(tl!=-1) tl=x-tl;
        if(tr!=-1) tr=tr-x;
        if(sl!=-1 && tl!= -1) ans=min(ans,max(sl,tl));
        if(sr!=-1 && tr!= -1) ans=min(ans,max(sr,tr));
        if(sl!=-1 && tr!= -1) ans=min(ans,sl*2+tr);
        if(tl!=-1 && sr!= -1) ans=min(ans,tl*2+sr);
        if(sr!=-1 && tl!= -1) ans=min(ans,sr*2+tl);
        if(tr!=-1 && sl!= -1) ans=min(ans,tr*2+sl);
        cout << ans << endl;
    }
return 0;
}
