#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>x(n),y(n);
    rep(i,n)cin>>x[i]>>y[i];
    ll ans=LONG_LONG_MAX;
    rep(a,n)rep(b,n)rep(c,n)rep(d,n){
        int L=x[a],R=x[b],D=y[c],U=y[d];
        if(R<L||U<D)continue;
        int cnt=0;
        rep(v,n){
            if(L<=x[v]&&x[v]<=R&&D<=y[v]&&y[v]<=U)cnt++;
        }
        if(cnt>=k)ans=min(ans,(ll)(R-L)*(U-D));
    }
    cout<<ans<<endl;
}