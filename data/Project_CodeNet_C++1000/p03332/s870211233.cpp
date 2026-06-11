
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////////////////
#define N 600004

ll kai[N];
ll kai2[N];
ll po(ll i,ll p){
    if(p==0)return 1;
    else if(p==1)return mod(i);
    else if(p%2==0)return po(mod(mod(i)*mod(i)),p/2);
    else  return mod(mod(i)*po(i,p-1));
}
void calc(){
    kai[0]=1;
    kai2[0]=1;
    rep(i,1,N-1){
        kai[i]=mod(kai[i-1]*i);
    }
    kai2[N-1]=po(kai[N-1],i_5);
    for(ll i=N-2;i>=0;i--){
        kai2[i]=mod(kai2[i+1]*(i+1));
    }
}
ll comb(ll n,ll k){
    if(n<k)return 0;
    else if(n==0)return 1;
    else return mod(mod(kai[n]*kai2[n-k])*kai2[k]);
}
ll bunbo(ll n){
    return po(n,i_5);
}

int main(){fastio;
    calc();
    ll n,a,b,k;cin>>n>>a>>b>>k;
    ll ans=0;
    rep(i,0,n){
        ll j=(k-a*i)/b;
        if(0<=j&&j<=n&&a*i+b*j==k){
            Add(ans,comb(n,i)*comb(n,j));
        }
    }
    cout<<ans<<endl;
    
    return 0;
}


