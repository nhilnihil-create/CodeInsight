#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll>x(n),y(n),z(n);
    rep(i,n)cin>>x[i]>>y[i]>>z[i];
    ll ans=0;
    rep(bit,1<<3){
        vector<ll>a(n);
        rep(i,n){
            if(bit&(1<<0))a[i]+=x[i];
            else a[i]-=x[i];
            if(bit&(1<<1))a[i]+=y[i];
            else a[i]-=y[i];
            if(bit&(1<<2))a[i]+=z[i];
            else a[i]-=z[i];
        }
        sort(a.rbegin(),a.rend());
        ll cnt=0;
        rep(i,m)cnt+=a[i];
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}