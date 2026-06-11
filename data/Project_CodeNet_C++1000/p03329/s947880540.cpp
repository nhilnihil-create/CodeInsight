#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	ll n; cin>>n;
      vl dp(1001000,MOD*10);
     dp[0]=0;
  //dp[1]=1;
  rep(i,0,n+1){
    chmin(dp[i+1],dp[i]+1);
    ll a=6,b=9;
    while(a+i<=n){
      chmin(dp[i+a],dp[i]+1);
      a*=6;
    }
    while(b+i<=n){
      chmin(dp[i+b],dp[i]+1);
      b*=9;
    }
  }
  cout<<dp[n]<<endl;
				
	
	return 0;
}
