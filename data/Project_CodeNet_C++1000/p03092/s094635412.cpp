#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n;
ll a,b;
int t[5010];
ll dp[5010][5010];
int pos[5010];

void solve(){
  cin >> n >> a >> b;
  vector<P> v;
  rep(i,n){
    cin >> t[i];
    t[i]-=1;
    pos[t[i]]=i;
  }
  
  rep(i,n+1){
    rep(j,n+1){
      dp[i][j]=INF;
    }
  }
  dp[0][0]=0;
  rep(i,n+1){
    rep(x,n+1){
      if(pos[i]>=x)dp[i+1][x]=min(dp[i+1][x],dp[i][x]+b);
      else dp[i+1][x]=min(dp[i+1][x],dp[i][x]+a);
      if(t[x]==i)dp[i+1][x+1]=min(dp[i+1][x+1],dp[i][x]);
      dp[i][x+1]=min(dp[i][x+1],dp[i][x]);
    }
  }
  rep(i,n+1){
    rep(j,n+1){
      //cout << i << " " << j << " " << dp[i][j] << endl;
    }
  }
  cout << dp[n][n] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}