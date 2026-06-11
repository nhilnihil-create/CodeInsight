#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef pair<l_l,ll> lll;
typedef vector<string> vs;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
const ll mod=1000000007;
ll dp[110][11000],dp_sum[110][11000];
ll a[110];
int main(){
    ll n,k;cin>>n>>k;
    rep(i,n)cin>>a[i];
    dp[0][0]=1;
    dp_sum[0][0]=1;
    rrep(i,n){
        for(int j=0;j<=k;j++){
            dp_sum[i-1][j]=dp[i-1][j];
            if(j>=1){
                dp_sum[i-1][j]+=dp_sum[i-1][j-1];
                dp_sum[i-1][j]%=mod;
            }
        }
        for(int j=0;j<=k;j++){
            dp[i][j]=dp_sum[i-1][j];
            if(j-a[i-1]-1>=0){
                dp[i][j]-=dp_sum[i-1][j-a[i-1]-1];
                dp[i][j]%=mod;
                if(dp[i][j]<0)dp[i][j]+=mod;
            }
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}