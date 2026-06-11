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
#define MT make_tuple
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

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<PLL> xs(N);
  cin >> xs;

  LL pr = (abs(xs[0].FF) + abs(xs[0].SS)) % 2;
  for(auto& x: xs){
	if(pr != (abs(x.FF) + abs(x.SS)) % 2){
	  cout << -1 << endl;
	  return 0;
	}
  }

  bool ev = (pr == 0);
  if(ev){
	for(auto& x: xs)
	  ++x.FF;
  }

  LL mx = 0;
  for(auto& p: xs) maxi(mx, abs(p.FF) + abs(p.SS));
  VL ans;
  LL i=1, p=0;
  for(;p<mx;){
	p += i;
	ans.PB(i);

	i *= 2;
  }

  if(SZ(ans) > 40){
	cout << -1 << endl;
	return 0;
  }

  int M = SZ(ans);
  cout << (M + (ev?1:0)) << endl
	   << ans << (ev ? " 1":"") << endl;
  for(auto p: xs){
	string str(M, '?');
	for(int i=M-1;i>=0;--i){
	  vector<tuple<LL,PLL,char>> ps;
	  for(LL dx=-1;dx<=1;dx+=2){
		LL tx = p.FF + dx * ans[i];
		ps.EB(abs(tx)+abs(p.SS), MP(tx,p.SS), "RL"[(dx+1)/2]);
	  }
	  for(LL dy=-1;dy<=1;dy+=2){
		LL ty = p.SS + dy * ans[i];
		ps.EB(abs(p.FF)+abs(ty), MP(p.FF,ty), "UD"[(dy+1)/2]);
	  }
	  SORT(ps);

	  str[i] = get<2>(ps[0]);
	  p = get<1>(ps[0]);
	}
	
	cout << str << (ev? "L" : "") << endl;
  }

  return 0;
}
