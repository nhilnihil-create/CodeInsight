#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    string s;cin>>s;

    ll dp[n+1][n+1]={};
    rep(j,n){
        dp[1][j]=1;
    }
    vector<ll> sum(n+1,0);
    //dp[i][j]の更新を行う
    for(int i=2;i<=n;i++){
        sum[0]=dp[i-1][0];
        for(int j=1;j<=n;j++) sum[j]=(sum[j-1]+dp[i-1][j])%mod;
        if(s[i-2]=='<'){
            for(int j=0;j<=n-i;j++){
                dp[i][j]=sum[n]-sum[j];
                if(dp[i][j]<0) dp[i][j]+=mod;
            }
        }else{
            for(int j=0;j<=n-i;j++){
                dp[i][j]=sum[j];
            }
        }
    }
    
    cout<<dp[n][0]<<endl;
    return 0;
}
