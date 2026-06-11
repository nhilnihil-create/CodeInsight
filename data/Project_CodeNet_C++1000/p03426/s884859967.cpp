#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    // Your code here!
    ll h,w,d;
    cin>>h>>w>>d;
    vector<pair<ll,ll>>a(h*w+1);
    rep(0,i,h){
        rep(0,j,w){
            ll a0;
            cin>>a0;
            a[a0]={i,j};
        }
    }
    ll d0[h*w+1];
    rep(0,i,d)d0[i]=0;
    rep(d,i,h*w+1){
        d0[i]=d0[i-d]+abs(a[i].first-a[i-d].first)+abs(a[i].second-a[i-d].second);
    }
    ll q;
    cin>>q;
    rep(0,i,q){
        ll l,r;
        cin>>l>>r;
        cout<<d0[r]-d0[l]<<endl;
    }
}
