#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,K;cin>>n>>K;
    vector<ll> x(n),y(n);
    rep(i,n)cin>>x[i]>>y[i];
    ll ans = 4*INF;
    rep(i,n)rep(j,n)rep(k,n)rep(l,n){
        ll lx=x[i],rx=x[j],ly=y[k],ry=y[l];
        if(lx>rx||ly>ry)continue;
        int cnt = 0;
        for(int m=0; m<n&&cnt<K; m++){
            if(lx<=x[m]&&x[m]<=rx&&ly<=y[m]&&y[m]<=ry)cnt++;
        }
        if(cnt==K)ans=min(ans,(lx-rx)*(ly-ry));
    }
    cout<<ans<<endl;
    return 0;
}