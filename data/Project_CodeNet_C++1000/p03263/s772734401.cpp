#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
//#pragma GCC optimize("Ofast")
//#define _GLIBCXX_DEBUG
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
//#define int ll
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define irep(it, stl) for(auto it = stl.begin(); it != stl.end(); it++)
#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define mp(p,q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define floatprec(dig) fixed << setprecision(dig)
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int;
#define invar(typ, var) typ var; cin >> var;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);}};
const int INF = INT_MAX / 2;
const ll LLINF = 1LL<<60;
constexpr ll MOD = 1000000007;
const double EPS = 1e-9;

struct op { int y; int x; int yy; int xx; };

signed main(void) {
  cin.tie(0); ios::sync_with_stdio(false);
  
  //一筆書きすればよい => 思いつかないよ！
  //奇数同士のマスのマッチングをするというのは思いついた
  
  int H, W;
  cin >> H >> W;
  vvi a(H, vi(W));
  rep(i, H) {
    rep(j, W) {
      cin >> a[i][j];
    }
  }
  
  //ラストでかつ奇数個目の奇数マスは無視
  //一筆書き
  int li = -1; int lj = -1;
  int ct = 0;
  for(int i = 0; i < H; i++) {
    for(int j_=0; j_<W; j_++) {
      int j = i % 2 == 0 ? j_ : W - j_ - 1;
      
      if(a[i][j] % 2 != 0) {
        li = i; lj = j;
        ct ++;
      }
    }
  }
  
  if(ct % 2 == 0) {
    li = -1; lj = -1;
  }
  
  
  int pri = -1;
  int prj = -1;
  vector<op> ops;
  
  for(int i = 0; i < H; i++) {
    for(int j_=0; j_<W; j_++) {
      int j = i % 2 == 0 ? j_ : W - j_ - 1;
      if(pri != -1) {
        ops.push_back({pri, prj, i, j});
        
        pri = i; prj = j;
        if(a[i][j] % 2 != 0) {
          //動かすのを終了
          pri = -1;
        }
      } else {
        if(a[i][j] % 2 != 0) {
          pri = i;
          prj = j;
        }
      }
    }
  }
  
  fin(ops.size());
  rep(i, ops.size()) {
    cout << (ops[i].y+1) << " " << (ops[i].x+1) << " " << (ops[i].yy+1) << " " << (ops[i].xx+1) << endl;
  }
  
  
  
}