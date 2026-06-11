#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
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
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll hpow(ll x,ll y){
    ll ans=1;
    ll i=x;
    if(y==0)return 1;
    while(y>0){
        if(y%2==1){
            ans=(ans*i)%i_7;
        }
        i=(i*i)%i_7;
        y=y/2;
        
    }
    return ans;
}

int main(){fastio
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll ka[n+1];
    ll kai=1;
    rep(i,1,n){
        kai=(kai*i)%i_7;
    }
    ka[1]=kai;
    rep(i,2,n){
        ka[i]=(kai*hpow(i,i_7-2))%i_7;
    }
    ll sum[n+1];
    sum[0]=0;
    rep(i,1,n){
        sum[i]=(sum[i-1]+ka[i])%i_7;
    }
    ll ans=0;
    rep(i,1,n){
        ans=(ans+a[i-1]*(sum[n+1-i]+sum[i]-kai))%i_7;
    }
    cout<<ans<<endl;
    
    return 0;
}


