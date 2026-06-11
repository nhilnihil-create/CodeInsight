#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<l_l> vpl;
typedef vector<string> vs;
typedef pair<l_l,ll> lll;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=1;i<=(n);i++)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=10100100100100100;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
template<class T> inline bool chmin(T& a,T b){
if(a>b){
a=b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a,T b){
if(a<b){
a=b;
return true;
}
return false;
}
ll n;
ll w[1100],s[1100],v[1100];
ll dp[1100][22000];
int main(){
    cin>>n;
    rep(i,n)cin>>w[i]>>s[i]>>v[i];
    vl block;
    rep(i,n)block.pb(i);
    sort(block.begin(),block.end(),[&](int x,int y){
        return s[x]+w[x]<s[y]+w[y];
    });
    for(int i=1;i<=n;i++){
        ll ind=block[i-1];
        for(int j=0;j<220000;j++){
            dp[i][j]=dp[i-1][j];
            if(j-w[ind]<=s[ind]&&j-w[ind]>=0){
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[ind]]+v[ind]);
            }
        }
    }
    ll ans=0;
    rep(i,220000)chmax(ans,dp[n][i]);
    cout<<ans<<endl;
    return 0;
}