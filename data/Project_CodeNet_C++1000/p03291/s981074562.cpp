//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};
ll dp[114514][3];
int main(){
    //cout << fixed << setprecision(15);
    string s;cin>>s;
    ll n=s.size();
    vl vec(114514);
    ll count=1;
    rep(i,n){
        vec[i]=count;
        if(s[i]=='?'){
            count*=3;
            count%=MOD;
        }
    }
    rep(i,n){
        if(s[i]=='A'){
            dp[i+1][0]=(dp[i][0]+vec[i])%MOD;
            dp[i+1][1]=dp[i][1];
            dp[i+1][2]=dp[i][2];
        }
        if(s[i]=='B'){
            dp[i+1][0]=dp[i][0];
            dp[i+1][1]=(dp[i][1]+dp[i][0])%MOD;
            dp[i+1][2]=dp[i][2];
        }
        if(s[i]=='C'){
            dp[i+1][0]=dp[i][0];
            dp[i+1][1]=dp[i][1];
            dp[i+1][2]=(dp[i][2]+dp[i][1])%MOD;
        }
        if(s[i]=='?') {
            dp[i+1][0]=(dp[i][0]*3+vec[i])%MOD;
            dp[i+1][1]=(dp[i][1]*3+dp[i][0])%MOD;
            dp[i+1][2]=(dp[i][2]*3+dp[i][1])%MOD;
        }
    }
    cout<<dp[n][2]<<endl;
}
