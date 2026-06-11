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

#define N 200005
ll n;
ll a[N];
stack<l_l>s;

void debug(ll m){
    cout<<m<<":";
    vector<l_l>v;
    while(!s.empty()){v.pb(s.top());s.pop();}
    reverse(v.begin(),v.end());
    for(auto x:v){
        rep(zz_,1,x.se)cout<<x.fi;
        s.push(x);
    }cout<<endl;
}

bool check(ll m){
    while(!s.empty())s.pop();
    ll l=0;
    rep(i,0,n-1){
        if(i==0){
            s.push({1,a[0]});
            l=a[0];
            //debug(m);
            continue;
        }
        if(l<a[i]){
            s.push({1,a[i]-l});
            l=a[i];
            //debug(m);
            continue;
        }
        bool f=true;
        while(!s.empty()){
            l_l fro=s.top();s.pop();
            if(l<a[i])f=false;
            l-=fro.se;
            if(l<a[i] && fro.fi!=m){
                if(f){
                    if(a[i]-l-1>=1)s.push({fro.fi,a[i]-l-1});
                    s.push({fro.fi+1,1});
                    l=a[i];
                }else{
                    if(fro.se-1>=1)s.push({fro.fi,fro.se-1});
                    s.push({fro.fi+1,1});
                    l+=fro.se;
                    if(a[i]-l>=1)s.push({1,a[i]-l});
                    l=a[i];
                }
                break;
            }
        }
        if(s.empty())return false;
        
        
        //debug(m);
    }
    return true;
}

int main(){fastio
    cin>>n;
    rep(i,0,n-1)cin>>a[i];
    ll ok=n+1,ng=0;
    while(abs(ok-ng)>1){
        ll m=(ok+ng)/2;
        if(check(m))ok=m;
        else ng=m;
    }
    cout<<ok<<endl;
    
    return 0;
}
