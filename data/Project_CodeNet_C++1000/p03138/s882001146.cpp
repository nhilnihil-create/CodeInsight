#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
#define i_7 998244353
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
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////

int main(){fastio
    ll n,k;cin>>n>>k;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll N=50;
    ll c[N];memset(c,0,sizeof(c));
    rep(i,0,n-1){
        rep(j,0,N-1){
            if((a[i]>>(N-1-j))&1)c[j]++;
        }
    }
    //rep(i,0,N-1)cout<<c[i]<<" ";cout<<endl;
    ll dp[N][2];memset(dp,-1,sizeof(dp));
    dp[0][1]=0;
    rep(i,1,N-1){
        ll p=1ll<<(N-1-i);
        if((k>>(N-1-i))&1){
            if(dp[i-1][1]>=0)dp[i][1]=dp[i-1][1]+(n-c[i])*p;//Xとして1使う
        }else{
            if(dp[i-1][1]>=0)dp[i][1]=dp[i-1][1]+c[i]*p;//Xとして1使わない
        }
        if((k>>(N-1-i))&1){
            if(dp[i-1][0]>=0)dp[i][0]=dp[i-1][0]+max(c[i],(n-c[i]))*p;
            if(dp[i-1][1]>=0)Max(dp[i][0],dp[i-1][1]+c[i]*p);
        }else{
            if(dp[i-1][0]>=0)dp[i][0]=dp[i-1][0]+max(c[i],(n-c[i]))*p;
        }
        Max(dp[i][1],dp[i][0]);
    }
    /*
    rep(j,0,1){
        rep(i,0,N-1)cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    */
    cout<<dp[N-1][1]<<endl;
    return 0;
}
