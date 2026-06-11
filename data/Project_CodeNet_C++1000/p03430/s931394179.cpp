#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second

#define DUMP(x) cout<<#x<<":"<<(x)<<endl
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class T>
istream& operator>>(istream& is, vector<T>& xs){
  for(auto& x: xs)
	is >> x;
  return is;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T>& xs){
  for(unsigned int i=0;i<xs.size();++i)
	os << (i?" ":"") << xs[i];
  return os;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

int dp[310][310][310];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string S;
  cin >> S;
  int K;
  cin >> K;
  int N = SZ(S);

  REP(i,N) dp[i][i+1][0] = 1;
  for(int len=2;len<=N;++len){
	for(int l=0,r=len;r<=N;++l,++r){
	  REP(k,K+1){
		if(S[l] == S[r-1])
		  maxi(dp[l][r][k], dp[l+1][r-1][k] + 2);
		maxi(dp[l][r][k], max(dp[l+1][r][k], dp[l][r-1][k]));
		maxi(dp[l][r][k+1], dp[l+1][r-1][k] + 2);
	  }
	}
  }

  int ans = 0;
  REP(i,K+1) maxi(ans, dp[0][N][i]);
  cout << ans << endl;

  return 0;
}
