#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

const ll INF=(ll)2e10;

int main(){
    ll a,b,q;
    cin>>a>>b>>q;
    vector<ll> s(a),t(b);
    rep(i,a) cin>>s[i];
    rep(i,b) cin>>t[i];
    rep(i,q){
        ll x;
        cin>>x;
        auto itrsl=lower_bound(rall(s),x,greater<ll>());
        auto itrsr=lower_bound(all(s),x);
        auto itrtl=lower_bound(rall(t),x,greater<ll>());
        auto itrtr=lower_bound(all(t),x);
        ll sl,sr,tl,tr;
        sl=max(x-*itrsl,(distance(s.rend(),itrsl)==0)*INF);
        sr=max(*itrsr-x,(distance(s.end(),itrsr)==0)*INF);
        tl=max(x-*itrtl,(distance(t.rend(),itrtl)==0)*INF);
        tr=max(*itrtr-x,(distance(t.end(),itrtr)==0)*INF);
        cout<<min({max(sl,tl),max(sr,tr),min(sl,sr)+min(tl,tr)+min({sl,sr,tl,tr})})<<endl;
    }
    return 0;
}