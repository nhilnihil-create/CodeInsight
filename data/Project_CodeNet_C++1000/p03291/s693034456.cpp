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
    string s;cin>>s;
    ll n;n=s.size();
    ll dp[n+1][4];
    rep(j,0,2)dp[0][j]=0;
    dp[0][3]=1;
    rep(i,1,n){
        if(s[i-1]=='A'){
            dp[i][0]=dp[i-1][0]+dp[i-1][3];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2];
            dp[i][3]=dp[i-1][3];
        }else if(s[i-1]=='B'){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=(dp[i-1][1]+dp[i-1][0])%i_7;
            dp[i][2]=dp[i-1][2];
            dp[i][3]=dp[i-1][3];
        }else if(s[i-1]=='C'){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=(dp[i-1][2]+dp[i-1][1])%i_7;
            dp[i][3]=dp[i-1][3];
        }else if(s[i-1]=='?'){
            dp[i][0]=(dp[i-1][0]*3+dp[i-1][3])%i_7;
            dp[i][1]=(dp[i-1][1]*3+dp[i-1][0])%i_7;
            dp[i][2]=(dp[i-1][2]*3+dp[i-1][1])%i_7;
            dp[i][3]=(dp[i-1][3]*3)%i_7;
        }
    }
    /*
    rep(i,0,n){
        rep(j,0,3){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }*/
    
    cout<<dp[n][2]%i_7<<endl;
    return 0;
}
