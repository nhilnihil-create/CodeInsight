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
////////////////////////////


int main(){fastio
    
    ll n;cin>>n;
    ll x[n],y[n],s[n],t[n];
    rep(i,0,n-1){
        cin>>x[i]>>y[i];
        s[i]=x[i]+y[i];
        t[i]=y[i]-x[i];
    }
    rep(i,1,n-1){
        if(abs(s[0]-s[i])%2==1){
            cout<<-1;return  0;
        }
    }
    vector<ll>ans;
    //ll N=3;
    ll N=36;
    rep(i,1,N)ans.pb((1ll<<i));
    rep(i,0,1)ans.pb(1);
    if(s[0]%2)ans.pb(1);
    sort(ans.rbegin(),ans.rend());
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";cout<<endl;
    rep(i,0,n-1){
        ll ps=-s[i],pt=-t[i];
        for(auto x:ans){
            if(ps>=0&&pt>=0){
                cout<<"D";
                ps-=x;
                pt-=x;
            }else if(ps>=0){
                cout<<"L";
                ps-=x;
                pt+=x;
            }else if(pt>=0){
                cout<<"R";
                ps+=x;
                pt-=x;
            }else{
                cout<<"U";
                ps+=x;
                pt+=x;
            }
        }
        cout<<endl;
    }
    
    
    
    return 0;
}
