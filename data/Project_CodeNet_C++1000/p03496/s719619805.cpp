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
ll inf=(ll)1E18;
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



int main(){fastio
    ll n;cin>>n;
    ll a[n+1];rep(i,1,n)cin>>a[i];
    ll maxi=-inf,flag=-1;
    vector<l_l> ans;
    rep(i,1,n){
        if(maxi<abs(a[i])){
            maxi=abs(a[i]);
            flag=i;
        }
    }
    if(maxi==0){
        cout<<0<<endl;
        return 0;
    }
    if(a[flag]<0){
        rep(i,1,n){
            if(i!=flag){
                ans.pb(l_l(flag,i));
            }
        }
        for(ll i=n;i>=2;i--){
            ans.pb(l_l(i,i-1));
        }
        cout<<ans.size()<<endl;
        rep(i,0,(ll)ans.size()-1){
            cout<<ans[i].first<<' '<<ans[i].second<<endl;
        }
    }else{
        rep(i,1,n){
            if(i!=flag){
                ans.pb(l_l(flag,i));
            }
        }
        for(ll i=1;i<=n-1;i++){
            ans.pb(l_l(i,i+1));
        }
        cout<<ans.size()<<endl;
        rep(i,0,(ll)ans.size()-1){
            cout<<ans[i].first<<' '<<ans[i].second<<endl;
        }
    }
    
    
    return 0;
}



