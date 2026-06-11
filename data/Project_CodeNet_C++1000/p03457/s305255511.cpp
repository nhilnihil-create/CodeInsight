#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll MOD = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n; cin>>n;
    ll t[n+1],x[n+1],y[n+1];
    t[0]=x[0]=y[0]=0;
    rep(i,n) cin>>t[i+1]>>x[i+1]>>y[i+1];
    bool can=true;
    rep(i,n){
        ll dist=abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
        ll dt=abs(t[i+1]-t[i]);
        if(dt<dist){
            can=false;
        }
        if(dist%2!=dt%2) can=false;
    }
    if(can) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}