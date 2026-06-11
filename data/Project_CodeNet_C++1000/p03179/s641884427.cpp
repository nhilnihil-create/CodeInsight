#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    string s;cin>>s;
    mat dp(n,vec(n+1));
    dp[0][0]=1;
    rep(i,n-1){
        REP(j,1,n){
            dp[i][j]=(dp[i][j]+dp[i][j-1])%inf;
        }
        rep(j,n){
            ll k=n-1-i;
            if(s[i]=='<'){
                dp[i+1][j]=(dp[i+1][j]+dp[i][j])%inf;
                dp[i+1][k]=(dp[i+1][k]-dp[i][j])%inf;
            }else{
                dp[i+1][0]=(dp[i+1][0]+dp[i][j])%inf;
                dp[i+1][j]=(dp[i+1][j]-dp[i][j])%inf;
            }
        }
    }
    REP(i,1,n)dp[n-1][i]=(dp[n-1][i]+dp[n-1][i-1])%inf;
    ll ans=0;
    rep(i,n){
        ans=(ans+dp[n-1][i])%inf;
    }
    if(ans<0)ans+=inf;
    cout<<ans<<endl;
}