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

void solve(int modu, int C, int N, vvi& c, vvi& D) {
  //変えた後の色がkのときの違和感合計
  //かつ，別のあまりなら，色が異ならないといけない
  
}

signed main(void) {
  cin.tie(0); ios::sync_with_stdio(false);
  
  int N, C;
  cin >> N >> C;
  
  vvi D(C, vi(C));
  
  rep(i, C) {
    rep(j, C) {
      cin >> D[i][j];
    }
  }
  
  vvi c(N, vi(N));
  rep(i, N) {
    rep(j, N) {
      cin >> c[i][j];
      c[i][j]--;
    }
  }
  vector<vector<ll>> dsum(3, vector<ll>(C));
  
  //modごと，各色に変えたときのコスト合計を算出
  //別に+1しなくてもmodは成立
  rep(i, N) {
    rep(j, N) {
      int orgcol = c[i][j];
      int m = (i + j) % 3;
      rep(k, C) {
        dsum[m][k] += (ll)D[orgcol][k];
      }
    }
  }
  
  int cc[3];
  int mval = INF;
  for(cc[0]=0; cc[0]<C; cc[0]++) {
    for(cc[1]=0; cc[1]<C; cc[1]++) {
      if(cc[0] == cc[1]) continue;
      for(cc[2]=0; cc[2]<C; cc[2]++) {
        if(cc[0] == cc[2] || cc[1] == cc[2]) continue;
        
        int iwa = 0;
        rep(it, 3) iwa += dsum[it][cc[it]];
        chmin(mval, iwa);
      }
    }
  }
  
  fin(mval);
  
}