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

ll n;
vector<ll>a;

template< typename T >
vector< T > convert_base(T x, T b) {
  vector< T > ret;
  T t = 1, k = abs(b);
  while(x) {
    ret.emplace_back((x * t) % k);
    if(ret.back() < 0) ret.back() += k;
    x -= ret.back() * t;
    x /= k;
    t *= b / k;
  }
  if(ret.empty()) ret.emplace_back(0);
  reverse(begin(ret), end(ret));
  return ret;
}
//桁DP
ll digit_dp(ll k){
  ll dp[45][2];//kはbitが立っているか確かめるだけ
  memset(dp,0,sizeof(dp));
  rep(i,45)dp[i][1]=-1;
  rep(i,40){
    ll bit=1LL<<(39-i);
    ll cnt=0;
    rep(j,n){
      if(bit&a[j])++cnt;
    }
    //演算を可換にする.
    if(k&bit)chmax(dp[i+1][1],dp[i][0]+cnt*bit);//Kより真に小さくなる
    if(dp[i][1]>-1)chmax(dp[i+1][1],dp[i][1]+max(n-cnt,cnt)*bit);
    if(!(k&bit))chmax(dp[i+1][0],dp[i][0]+cnt*bit);
    else chmax(dp[i+1][0],dp[i][0]+max(n-cnt,cnt)*bit);
	}
  ll ans=max(dp[40][0],dp[40][1]);
  return ans;
}


void solve(){
  ll k;
  cin>>n>>k;
  a.resize(n);
  rep(i,n)cin>>a[i];
  if(k)cout<<digit_dp(k);
  else {
    ll sum=0;
    rep(i,n)sum+=a[i];
    cout<<sum;
  }
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
