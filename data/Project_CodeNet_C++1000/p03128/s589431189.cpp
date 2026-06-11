#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<deque>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#include<regex>
#include<bitset>
#include<complex>
#include<chrono>
#include<random>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

ll gcd(ll n, ll m) {
	ll tmp;
	while (m!=0) {
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m) {
	return abs(n * m) / gcd(n, m);//gl=xy
}
 
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
 
using namespace std;

//ここから
void solve(){
  int n,m;
  cin>>n>>m;
  int sz[9]={2,5,5,4,5,6,3,7,6};
  vector<int>a(m);
  rep(i,m)cin>>a[i];
  vector<vector<string>>dp(n+5,vector<string>(m,"0"));
  rep(i,m)dp[0][i]="";
  rep(i,n){
    rep(j,m){
      rep(k,m){
        if(i+sz[a[k]-1]>n)continue;
        if(dp[i][j]=="0")continue;
        if(dp[i+sz[a[k]-1]][k].size()==dp[i][j].size()+1)chmax(dp[i+sz[a[k]-1]][k],dp[i][j]+to_string(a[k]));
        else if(dp[i+sz[a[k]-1]][k].size()<dp[i][j].size()+1)dp[i+sz[a[k]-1]][k]=dp[i][j]+to_string(a[k]);
      }
    }
  }
  string ans="";
  rep(i,m){
    if(ans.size()==dp[n][i].size())chmax(ans,dp[n][i]);
    else if(ans.size()<dp[n][i].size())ans=dp[n][i];
  }
  cout<<ans;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}