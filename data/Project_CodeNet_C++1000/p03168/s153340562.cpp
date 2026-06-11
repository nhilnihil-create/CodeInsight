#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vll>;
const double EPS = 1e-9;
const ll MOD=1e9+7;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
  ll n; cin>>n;
  vector<double> p(n);
  rep(i,n) cin>>p[i];
  vector<vector<double>> dp(n,vector<double>(n+1,0.0));
  dp[0][0]=1-p[0];
  dp[0][1]=p[0];
  for( ll i=1; i<n; i++ ){
    dp[i][0] = dp[i-1][0]*(1-p[i]);
    for( ll j=1; j<=i+1; j++ ){
      dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1-p[i]);
    }
  }
  double psum=accumulate(dp[n-1].begin()+(n>>1)+1,dp[n-1].end(),0.0);
  cout<<setprecision(10)<<psum<<endl;
}
