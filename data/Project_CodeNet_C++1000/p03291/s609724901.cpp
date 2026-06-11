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

ll dp[100005][4];
void solve(){
  string s;
  cin>>s;
  memset(dp,0,sizeof(dp));
  int n=s.size();
  dp[0][0]=1;
  rep(i,n){
    rep(j,4){
      if(j<3){//まだ選べる
        if(s[i]==char('A'+j))dp[i+1][j+1]=+dp[i][j];//?でなくて選ぶとき
        else if(s[i]=='?')dp[i+1][j+1]+=dp[i][j];//?で選ぶとき
        dp[i+1][j+1]%=mod;      
        if(s[i]=='?'){
          dp[i+1][j]+=3*dp[i][j];//?で選ばないとき
          dp[i+1][j]%=mod;
        }
        else {
          dp[i+1][j]+=dp[i][j];//それ以外で選ばないとき
          dp[i+1][j]%=mod;
        }
      }
      else {//もう選べない
        if(s[i]=='?'){
          dp[i+1][j]+=3*dp[i][j];//これ以上選べない
          dp[i+1][j]%=mod;
        }
        else {
          dp[i+1][j]+=dp[i][j];//これ以上選べない
          dp[i+1][j]%=mod;
        }
      }
    }
  }
  cout<<dp[n][3];
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}