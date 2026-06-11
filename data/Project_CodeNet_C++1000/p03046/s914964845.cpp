//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
////////////////////////////

ll m,k;
vector<ll> putans(){
    vector<ll>res;
    if((1ll<<m)<=k){
        res.pb(-1);return res;
    }
    if(m==0){
        rep(q,1,2)res.pb(0);return res;
    }
    if(m==1){
        if(k==0){
            rep(i,0,1)rep(j,0,1)res.pb(i);
        }else{
            res.pb(-1);
        }
        return res;
    }
    
    ll y=k/4*4;
    ll z=k-y;
    vector<ll>a;rep(i,0,3)rep(j,0,1)a.pb(i+y);
    do{
        bool flag=true;
        rep(i,y,y+3){
            ll s1=-1,s2=-1;
            rep(j,0,7){
                if(a[j]==i){
                    if(s1==-1)s1=j;
                    else s2=j;
                }
            }
            ll xo=0;
            rep(j,s1,s2){
                xo^=a[j];
            }
            if(xo!=k)flag=false;
        }
        if(flag)break;
    }while(next_permutation(a.begin(),a.end()));
    vector<ll>v;
    rep(i,0,7){
        v.pb(a[i]);
    }
    vector<ll>fro;
    rep(i,0,(1ll<<m)-1){
        if(y<=i&&i<=y+3)continue;
        fro.pb(i);
    }
    ll pos=0;
    rep(i,0,v.size()-1){
        if(v[i]==k){
            pos=i;break;
        }
    }
    rep(i,0,v.size()-1){
        if(i==pos){
            reverse(fro.begin(),fro.end());
            for(auto x:fro)res.pb(x);
            res.pb(v[i]);
            reverse(fro.begin(),fro.end());
            for(auto x:fro)res.pb(x);
        }else{
            res.pb(v[i]);
        }
    }
    return res;
}
bool check(vector<ll>a){
    rep(i,0,(1<<m)-1){
        ll s1=-1,s2=-1;
        rep(j,0,a.size()-1){
            if(a[j]==i){
                if(s1==-1)s1=j;
                else s2=j;
            }
        }
        ll xo=0;
        rep(j,s1,s2){
            xo^=a[j];
        }
        if(xo!=k)return false;
    }
    return true;
}
int main(){fastio
    cin>>m>>k;
    vector<ll>v=putans();
    for(auto x:v)cout<<x<<" ";
    return 0;
    //cin>>m>>k;
    rep(i,2,5){
        rep(j,0,(1<<i)-1){
            m=i;k=j;
            vector<ll>v=putans();
            //for(auto x:v)cout<<x<<" ";
            cout<<m<<" "<<k<<" "<<check(v)<<endl;
        }
    }
    
    
    return 0;
}
