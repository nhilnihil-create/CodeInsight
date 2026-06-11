#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//read_kaisetsu
int main() {
    int n,k;cin>>n>>k;
    ll x[n],y[n],x1[n],y1[n];
    rep(i,n){
        cin>>x[i]>>y[i];
        x1[i]=x[i];
        y1[i]=y[i];
    }
    sort(x1,x1+n);
    sort(y1,y1+n);
    ll ans = (x1[n-1]-x1[0])*(y1[n-1]-y1[0]);
    rep(i,n)rep(j,n)rep(l,i)rep(m,j){
        int cc=0;
        ll x_s = min(x[i],x[l]);
        ll x_l = max(x[i],x[l]);
        ll y_s = min(y[j],y[m]);
        ll y_l = max(y[j],y[m]);
        rep(t,n)if(x[t]>=x_s && x[t]<=x_l && y[t]>=y_s && y[t]<=y_l)++cc;
        
        if(cc>=k)ans = min(ans, (x_l - x_s)*(y_l - y_s));
    }
    cout<<ans<<endl;
	return 0;
}