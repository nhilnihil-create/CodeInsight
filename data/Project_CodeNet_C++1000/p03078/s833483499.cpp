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
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////

struct ITEM{
    ll sum;
    ll xp,yp,zp;
    bool operator<(const ITEM op)const{
        return sum<op.sum;
    }
};

ll N=10000*10000;
ll M=10000;

int main(){fastio
    ll x,y,z,k;cin>>x>>y>>z>>k;
    ll a[x],b[y],c[z];
    rep(i,0,x-1)cin>>a[i];
    rep(i,0,y-1)cin>>b[i];
    rep(i,0,z-1)cin>>c[i];
    sort(a,a+x);sort(b,b+y);sort(c,c+z);
    reverse(a,a+x);reverse(b,b+y);reverse(c,c+z);
    priority_queue<ITEM>q;
    q.push({a[0]+b[0]+c[0],0,0,0});
    set<ll>used;
    while(k>0){
        ITEM r=q.top();q.pop();
        ll pos=r.xp*N+r.yp*M+r.zp;
        if(used.find(pos)!=used.end()){
            continue;
        }
        k--;
        used.insert(pos);
        cout<<r.sum<<endl;//":";
        if(r.xp!=x-1)q.push({a[r.xp+1]+b[r.yp]+c[r.zp],r.xp+1,r.yp,r.zp});
        if(r.yp!=y-1)q.push({a[r.xp]+b[r.yp+1]+c[r.zp],r.xp,r.yp+1,r.zp});
        if(r.zp!=z-1)q.push({a[r.xp]+b[r.yp]+c[r.zp+1],r.xp,r.yp,r.zp+1});
        //cout<<r.xp<<" "<<r.yp<<" "<<r.zp<<" "<<pos<<endl;
    }
    
    return 0;
}
