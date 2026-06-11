#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(n,v) cout<<#v<<":";for(int i=0;i<n;i++)cout<<v[i]<<" ";cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    ll n;cin>>n;
    vector<ll> idx(200010,-1),dp(n+1,0),a(n+1);
    rep(i,n){
        cin>>a[i];
    } 
    dp[0]=1ll;
    for(ll i=0;i<n;i++){
        ll clr=a[i];
        if(idx[clr]==-1||idx[clr]==i-1) dp[i+1]=dp[i];
        else dp[i+1]=(dp[i]+dp[idx[clr]+1])%mod;
        idx[clr]=i;
    }
    cout<<dp[n]%mod<<endl;
    return 0;
}