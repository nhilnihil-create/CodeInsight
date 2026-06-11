//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
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

void no(){
    cout<<-1;exit(0);
}

int main(){fastio
    ll n,a,b;cin>>n>>a>>b;
    if(a*b<n)no();
    if(a+b>n+1)no();
    vector<ll>v[a];
    ll cnt=1;
    rep(i,0,a-1){
        if(i==0){
            rep(z,1,b){
                v[i].pb(cnt);cnt++;
            }
            continue;
        }
        if(i==a-1){
            while(cnt<=n){
                v[i].pb(cnt);cnt++;
            }
            continue;
        }
        ll k=(n-cnt+1)/(a-i);
        while(k--){
            v[i].pb(cnt);cnt++;
        }
    }
    rep(i,0,a-1){
        reverse(v[i].begin(),v[i].end());
        for(auto x:v[i])cout<<x<<" ";
    }
    
    return 0;
}

/*
 1 7
 2 4
 2 5
 2 6
 3 3
 3 4
 3 5
 4 2
 4 3
 4 4
 5 2
 5 3
 6 2
 7 1
 */
