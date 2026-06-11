#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll p[1100];
ll x[1100],y[1100],z[1100];
int main(){
    ll n,m,ans=0;
    cin>>n>>m;
    rep(i,0,n)cin>>x[i]>>y[i]>>z[i];
    
    rep(i,0,2){
        rep(j,0,2){
            rep(k,0,2){
                ll cnt=0,pos=0,tmp=0;
                if(i==0){
                    if(j==0){
                        if(k==0){
                            rep(h,0,n)p[h]=x[h]+y[h]+z[h];
                            sort(p,p+n,greater<ll>());
                            rep(g,0,m)tmp+=p[g];
                        }
                        else{
                            rep(h,0,n)p[h]=x[h]+y[h]-z[h];
                            sort(p,p+n,greater<ll>());
                            rep(g,0,m)tmp+=p[g];
                        }
                    }
                    else{
                        if(k==0){
                            rep(h,0,n)p[h]=x[h]-y[h]+z[h];
                            sort(p,p+n,greater<ll>());
                            rep(g,0,m)tmp+=p[g];
                        }
                        else{
                            rep(h,0,n)p[h]=x[h]-y[h]-z[h];
                            sort(p,p+n,greater<ll>());
                            rep(g,0,m)tmp+=p[g];
                        }
                    }
                }
                else{
                    if(j==0){
                        if(k==0){
                            rep(h,0,n)p[h]=-x[h]+y[h]+z[h];
                            sort(p,p+n,greater<ll>());
                            rep(g,0,m)tmp+=p[g];
                        }
                        else{
                            rep(h,0,n)p[h]=-x[h]+y[h]-z[h];
                            sort(p,p+n,greater<ll>());
                            rep(g,0,m)tmp+=p[g];
                        }
                    }
                    else{
                        if(k==0){
                            rep(h,0,n)p[h]=-x[h]-y[h]+z[h];
                            sort(p,p+n,greater<ll>());
                            rep(g,0,m)tmp+=p[g];
                        }
                        else{
                            rep(h,0,n)p[h]=-x[h]-y[h]-z[h];
                            sort(p,p+n,greater<ll>());
                            rep(g,0,m)tmp+=p[g];
                        }
                    }
                }
                ans=max(ans,tmp);
            }
        }
    }
    cout<<ans;
}