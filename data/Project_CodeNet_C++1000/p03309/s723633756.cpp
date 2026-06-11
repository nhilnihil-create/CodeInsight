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

signed main(void) {
  cin.tie(0); ios::sync_with_stdio(false);
  
  int N;
  cin >> N;
  vll A(N);
  rep(i, N) {
    cin >> A[i];
    A[i] -= i + 1;
  }
  
  //中央値を求める
  sort(all(A));
  ll mv;
  if(N%2==0) {
    mv = (ll)((double)(A[N/2-1] + A[N/2]) / 2 + 0.5);
  } else {
    mv = A[N/2];
  }
  
  ll v = 0;
  rep(i, N) {
    v += abs(A[i] - mv);
  }
  fin(v);
  
  
  // //Aの平均
  // ll asum = 0;
  // rep(i, N) asum += A[i];
  
  // asum /= N;
  
  // //Nだけループ
  // ll minv = LLINF;
  // for(int j=asum+N/2-100; j<=asum+N/2+100; j++) {
  //   ll s = 0;
  //   rep(i, N) {
  //     s += abs(A[i] - (j + i + 1));
  //   }
  //   chmin(minv, s);
  // }
  // fin(minv);
  
  // //傾きは，1で固定
  
  // //切片を求める
  // //平均
  // ll sumy = 0;
  // ll sumx = 0;
  // rep(i, N) {
  //   sumx += (i + 1);
  //   sumy += A[i];
  // }
  
  // //ll b = (sumy / N) - 1 * (sumx / N);
  // ll b = (sumy - sumx) / N;
  
  // //整数なので，bとb+1で調べる
  // ll diff1 = 0;
  // rep(i, N) {
  //   diff1 += abs(A[i] - (b + 1));
  // }
  
  // ll diff2 = 0;
  // rep(i, N) {
  //   diff2 += abs(A[i] - (b + 1 + 1));
  // }
  
  // if(diff1 < diff2) {
  //   fin(diff1); 
  // }else {
  //   fin(diff2);
  // }
}