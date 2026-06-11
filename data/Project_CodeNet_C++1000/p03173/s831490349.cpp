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
ll dp[440][440],sum[440][440];
int main(){
    ll n;cin>>n;
    vl a(n);rep(i,n)cin>>a[i];
    rep(i,n){
        for(int j=i+1;j<=n;j++){
            sum[i][j]=a[j-1];
            if(j-1>=0)sum[i][j]+=sum[i][j-1];
        }
    }
    rep(i,n){
        rep(j,n+1){
            dp[i][j]=LINF;
        }
        dp[i][i+1]=0;
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i<n;i++){
            if(i+len>n)continue;
            int j=i+len;
            for(int k=i+1;k<j;k++){
                //if(i==2&&j==4)cout<<dp[2][4]<<endl;
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+sum[i][j]);
            }
        }
    }
    /*cout<<sum[2][4]<<endl;
    cout<<dp[2][3]<<endl;
    cout<<dp[2][4]<<endl;*/
    cout<<dp[0][n]<<endl;
    return 0;
}