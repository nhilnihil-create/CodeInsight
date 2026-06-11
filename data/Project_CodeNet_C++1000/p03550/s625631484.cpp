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

ll n,z,w;
ll a[2001];
ll memo[2001][2001][2];

ll hoge(ll i,ll j,ll k){
    if(memo[i][j][k]!=-1){
        return memo[i][j][k];
    }
    if(i==n || j==n){
        return memo[i][j][k]=abs(a[i]-a[j]);
    }
    if(k==0){
        return memo[i][j][k]=max(hoge(max(i,j)+1,j,0),hoge(max(i,j)+1,j,1));
    }else{
        return memo[i][j][k]=min(hoge(i,max(i,j)+1,0),hoge(i,max(i,j)+1,1));
    }
}

int main(){fastio
    cin>>n>>z>>w;
    rep(i,1,n)cin>>a[i];
    a[0]=w;
    rep(i,0,n){
        rep(j,0,n){
            rep(k,0,1){
                memo[i][j][k]=-1;
            }
        }
    }
    cout<<hoge(0,0,0)<<endl;
    
    return 0;
}



