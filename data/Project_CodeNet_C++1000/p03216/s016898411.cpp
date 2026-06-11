//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
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
///////////////////////////

int main(){fastio
    ll n;cin>>n;
    string s;cin>>s;
    s='a'+s;
    string dmc="DMC";
    ll q;cin>>q;
    while(q--){
        ll k;cin>>k;
        ll dp[n+1][4];memset(dp,0,sizeof(dp));
        rep(i,1,n){
            rep(j,0,3)dp[i][j]=dp[i-1][j];
            if(i-k>=0){
                if(s[i-k]=='D'){
                    dp[i][0]--;
                    dp[i][2]-=dp[i-1][1]-dp[i-k][1];
                }else if(s[i-k]=='M'){
                    //dp[i][1]--;
                }
            }
            if(s[i]=='D'){
                dp[i][0]++;
            }else if(s[i]=='M'){
                dp[i][1]++;
                dp[i][2]+=dp[i][0];
            }else if(s[i]=='C'){
                dp[i][3]+=dp[i][2];
            }
        }
        /*
        rep(j,0,3){
            rep(i,0,n){
                cout<<dp[i][j]<<" ";
            }cout<<endl;
        }*/
        cout<<dp[n][3]<<endl;
    }
    return 0;
}
