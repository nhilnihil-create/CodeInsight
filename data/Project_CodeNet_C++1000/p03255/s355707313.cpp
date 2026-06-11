//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#include "boost/multiprecision/cpp_int.hpp"
typedef boost::multiprecision::cpp_int LL;
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
typedef pair<dd,dd> d_d;
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
#define endl "\n"
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

//////////////////////////



int main(){fastio
    
    ll n,X;cin>>n>>X;
    LL a[n];rep(i,0,n-1)cin>>a[i];
    LL ans=(LL)1E18;
    LL sum[n+1];
           sum[n]=0;
    for(ll i=n-1;i>=0;i--)sum[i]=sum[i+1]+a[i];
    rep(k,1,n){
        LL s=(n+k)*X;
        ll pos=n;
        LL kei=5;
        s+=kei*(sum[max(0,pos-2*k)]-sum[pos]);
        pos-=2*k;
        while(pos>0){
            kei+=2;
            s+=kei*(sum[max(0,pos-k)]-sum[pos]);
            pos-=k;
        }
        //chmin(ans,s);
        if(ans>s){
            ans=s;
        }
        //cout<<k<<" "<<s<<endl;
    }
    cout<<ans<<endl;
    
    return 0;
}
