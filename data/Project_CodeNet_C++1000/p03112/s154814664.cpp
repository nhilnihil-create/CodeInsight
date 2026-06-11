#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll a,b,q;cin >>a>>b>>q;
    vector<ll>s(a);
    vector<ll>t(b);
    for (int i = 0; i < a; ++i) {
        cin >>s[i];
    }
    for (int i = 0; i < b; ++i) {
        cin >>t[i];
    }
    for (int i = 0; i < q; ++i) {
        ll x;cin >>x;
        ll sf,sb,tf,tb;
        ll key=lower_bound(all(s),x)-s.begin();
        if(s[key]==x){
            sf=x;sb=x;
        }
        else {
            sb=(s[key]<x)?INFll/3:s[key];
            sf=(key==0)?-INFll/3:s[key-1];
        }
        key=lower_bound(all(t),x)-t.begin();
        if(t[key]==x){
            tf=x;tb=x;
        }
        else {
            tb=(t[key]<x)?INFll/3:t[key];
            tf=(key==0)?-INFll/3:t[key-1];
        }
        sb-=x;
        tb-=x;
        sf=x-sf;
        tf=x-tf;
//        cout <<sf<<" "<<sb<<endl;
//        cout <<tf<<" "<<tb<<endl;
        ll ans;
        ans=max(sb,tb);
        ans=min(ans,max(sf,tf));
        ans=min(ans,2*sf+tb);
        ans=min(ans,sf+2*tb);
        ans=min(ans,2*sb+tf);
        ans=min(ans,sb+2*tf);
        cout <<ans <<endl;
    }
    return 0;
}
