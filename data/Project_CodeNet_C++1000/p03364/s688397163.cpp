#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

// 考察
// 対称性は斜めに遷移させても変わらない
// -> (A,B) == (A+x,B+x)
// 調べるべきもの
// -> if n=3: (1,0) == (2,1) == (0,2) == stop!! (1,0)
// -> A,Bのdiffが異なるものだけ調べて対象の場合は、ans += n

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string board[n];
  rep(i,n) cin >> board[i];

  ll ans = 0;

  rep(diff,n){ // a,b の組み合わせループ(aを固定)
    int b = (diff) % n;
    bool flag = true;
    rep(_i,n)rep(_j,n){
      int i = _i;
      int j = (_j + b) % n;
      int ri = _j;
      int rj = (_i+b) % n;
      if(board[i][j] != board[ri][rj]) flag = false;
    }
    if(flag) ans += n;
  }

  cout << ans << "\n";
  return 0;
}
