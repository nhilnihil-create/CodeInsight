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

int main(){
    ll n;cin>>n;
    ll b[n+1];rep(i,1,n)cin>>b[i];
    b[0]=inf;
    ll ans[n];
    rep(i,0,n-1){
        for(ll j=n;j>=1;j--){
            if(b[j]==j){
                //cout<<j<<endl;
                ans[n-1-i]=j;
                rep(k,j,n-1){
                    b[k]=b[k+1];
                }
                b[n]=0;
                break;
            }else if(j==1){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    rep(i,0,n-1){
        cout<<ans[i]<<endl;
    }
    
    return 0;
}

