#include <bits/stdc++.h>
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
///////////////////////////

bool comx(l_l a, l_l b){
    return a.first<b.first;
}
bool comy(l_l a, l_l b){
    return a.second<b.second;
}

int main(){
    ll n,k;cin>>n>>k;
    ll a[n],b[n];
    vector<l_l> p;
    rep(i,0,n-1){
        cin>>a[i]>>b[i];
        p.pb(make_pair(a[i],b[i]));
    }
    sort(p.begin(),p.end(),comy);
    vector<l_l> v;
    ll ans=1E18*5;
    rep(i,0,n-1){
        v.clear();
        rep(j,i,n-1){
            v.pb(p[j]);
            if(v.size()<k)continue;
            sort(v.begin(),v.end(),comx);
            rep(l,0,v.size()-k){
                ans=min(ans,(p[j].second-p[i].second)*(v[l+k-1].first-v[l].first));
            }
            
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
