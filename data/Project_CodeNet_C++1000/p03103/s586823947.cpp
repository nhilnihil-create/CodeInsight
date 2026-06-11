#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> ab(n);

    rep(i,n){
        ll a,b;
        cin>>a>>b;
        ab[i]=make_pair(a,b);
    }
    sort(ab.begin(),ab.end());
    ll num=m;
    ll ans=0;
    rep(i,n){
        if(num>ab[i].second){
            ans+=ab[i].first*ab[i].second;
            num-=ab[i].second;
        }
        else{
            ans+=ab[i].first*num;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}