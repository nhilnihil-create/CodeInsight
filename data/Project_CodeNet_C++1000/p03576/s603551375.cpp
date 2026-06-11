#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
int main(){
    ll n,k;cin>>n>>k;
    vl x(n),y(n),xarray,yarray;
    rep(i,n){
        cin>>x[i]>>y[i];
        xarray.push_back(x[i]);
        yarray.push_back(y[i]);
    }
    sort(xarray.begin(),xarray.end());
    sort(yarray.begin(),yarray.end());
    ll ans=(xarray[n-1]-xarray[0])*(yarray[n-1]-yarray[0]);
    //cout<<ans<<endl;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            rep(K,n){
                for(int l=K+1;l<n;l++){
                    ll cnt=0;
                    ll lx=xarray[i],rx=xarray[j];
                    ll by=yarray[K],uy=yarray[l];
                    rep(t,n){
                        if(lx<=x[t]&&x[t]<=rx&&by<=y[t]&&y[t]<=uy) cnt++;
                    }
                    //cout<<i<<" "<<j<<" "<<cnt<<" "<<(rx-lx)*(uy-by)<<endl;
                    if(cnt>=k) ans=min(ans,(rx-lx)*(uy-by));
                    //cout<<ans<<endl;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}