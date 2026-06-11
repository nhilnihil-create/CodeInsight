#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;




int main(){
    ll a,b,q;cin>>a>>b>>q;
    vector<ll> s(a+2),t(b+2);
    s[0]=-1e18;t[0]=-1e18;
    rep(i,0,a)cin>>s[i+1];
    rep(i,0,b)cin>>t[i+1];
    s[a+1]=1e18;t[b+1]=1e18;
    rep(i,0,q){
        ll x;cin>>x;
        ll sr=lower_bound(s.begin(),s.end(),x)-s.begin();
        ll sl=sr-1;
        ll tr=lower_bound(t.begin(),t.end(),x)-t.begin();
        ll tl=tr-1;
        
        sr=s[sr];
        sl=s[sl];
        tr=t[tr];
        tl=t[tl];
        vector<ll> t;
        t.push_back(max(sr-x,tr-x));
        t.push_back(max(x-sl,x-tl));
        t.push_back(2*(x-sl)+tr-x);
        t.push_back(2*(x-tl)+sr-x);
        t.push_back(2*(sr-x)+x-tl);
        t.push_back(2*(tr-x)+x-sl);
        sort(t.begin(),t.end());
        cout<<t[0]<<endl;
    }
    
}
    







