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
/*
考察メモ
2本辿ることによって辿り着けるような頂点の組に辺を張る場合は完全グラフになる
では、2本辿ることによって辿り着けるような頂点の組に辺を張る場合は？
2部グラフになりそう(もともと二部グラフでなければ破綻しているのでは。。。)
もともと二部グラフなら -> 二部グラフになりそう
*/
ll n,m;
const int MAX_N = 100000;
VI edges[MAX_N];
bool used[MAX_N][2];

void dfs(int current, int col){
  for(int to: edges[current]){
    if(!used[to][!col]){
      used[to][!col] = true;
      dfs(to,!col);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--,b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  
  used[0][0] = true;
  dfs(0,0);

  ll col0 = 0;
  rep(i,n){
    if( used[i][0] && used[i][1] ){ // 二部グラフでない
      cout << n*(n-1)/2 - m << endl;
      return 0;
    }
    if(used[i][0]) col0 ++;
  }

  cout << (n-col0) * col0 - m << endl;
  return 0;
}
