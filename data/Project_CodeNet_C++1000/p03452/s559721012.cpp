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



int main(){fastio
    ll n,m;cin>>n>>m;
    vector<l_l>v[n+1];
    rep(i,1,m){
        ll a,b,c;cin>>a>>b>>c;
        v[a].pb(l_l(b,c));
        v[b].pb(l_l(a,-c));
    }
    ll d[n+1];rep(i,1,n)d[i]=inf;
    rep(i,1,n){
        if(d[i]==inf){
            d[i]=0;
            queue<ll>q;q.push(i);
            while(!q.empty()){
                ll t=q.front();q.pop();
                for(auto y:v[t]){
                    ll to=y.fi,dis=y.se;
                    if(d[to]==inf){
                        d[to]=d[t]+dis;
                        q.push(to);
                    }else{
                        if(d[to]!=d[t]+dis){
                            cout<<"No"<<endl;return 0;
                        }
                    }
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
