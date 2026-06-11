#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(ll i=ll(x);i<(ll)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<ll,ll>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;



int main(){
    ll n;
    cin>>n;
    vector<ll>x(n),y(n),z(n);
    int sx,sy,sz;
    rep(i,n){
        cin>>x[i]>>y[i]>>z[i];
        if(z[i]>0){
            sx=x[i];
            sy=y[i];
            sz=z[i];
        }
    }
    ll ax,ay,az;
    rep(i,101)rep(j,101){
        bool ok=true;
        ll h=sz+abs(i-sx)+abs(j-sy);
        rep(k,n){
            ll tmp=h-abs(i-x[k])-abs(j-y[k]);
            tmp=max(tmp,0ll);
            if(tmp!=z[k]){
                ok=false;
                break;
            }
        }
        if(ok){
            ax=i;
            ay=j;
            az=h;
            break;
        }
    }
    cout<<ax<<" "<<ay<<" "<<az<<endl;
    return 0;
}