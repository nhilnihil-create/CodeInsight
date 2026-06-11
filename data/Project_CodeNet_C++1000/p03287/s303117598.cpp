#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n,m; cin>>n>>m;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    map<int,int> mp;
    int pre=0; mp[0]++;
    rep(i,n){
        pre+=p[i]; pre%=m; mp[pre]++;
    }
    ll ans=0;
    for(auto &v: mp){
        ll a=v.second;
        a=a*(a-1)/2;
        ans+=a;
    }
    cout<<ans<<endl;
    return 0;
}