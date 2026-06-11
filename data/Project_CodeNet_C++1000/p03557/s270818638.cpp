
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin>>n;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    rep(i,n) cin>>c[i];
    sort(a.begin(),a.end());
//    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll ans=0;
    rep(i,n){
        ll s=lower_bound(a.begin(),a.end(),b[i])-a.begin();
        ll s1=c.end()-lower_bound(c.begin(),c.end(),b[i]+1);
        ans+=s*s1;
   }
    cout<<ans<<endl;
    return 0;
}
