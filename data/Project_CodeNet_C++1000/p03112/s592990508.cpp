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
#include <iomanip>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define irep(it, stl) for(auto it = stl.begin(); it != stl.end(); it++)
#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define mp(p,q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
int dx8[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy8[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dx4[4] = {1, 0, -1, 0};
int dy4[4] = {0, 1, 0, -1};
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){ fill((T*)array, (T*)(array+N), val); }
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);}};
const int INF = INT_MAX;
const ll LLINF = 1LL<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };


int main() {
   
  int A,B,Q;
  cin >> A >> B >> Q;
  vll S(A);
  vll T(B);
  rep(i,A){
      cin >> S[i];
      
  }
  rep(j,B){
      cin >> T[j];
  }
  S.push_back(LLINF);S.push_back(-LLINF);sort(S.begin(),S.end());//二分探索で配列外にならないように
  T.push_back(LLINF);T.push_back(-LLINF);sort(T.begin(),T.end());

  rep(q,Q){
      ll x;
      cin >> x;
      ll res = LLINF;

      //最初にsの前後
      rep(i,2){
           //indexは0から始めるので注意
           //0だったら前方、1だったら後方,例えば[10,20,500,1000]、x=40とすると前方なら500のindex-1で20のindex、つまりlowerboundでは自分以上の数が初めて出るindexが返る、以上なので40があったならそこ、なので40未満で最大が欲しければ-1、後方ならupperboundは初めて自分を超過するやつ、なので40があってもだめで今回だったらそのまま500
          ll first = (i ? S[lower_bound(S.begin(),S.end(),x)-S.begin()-1] : S[upper_bound(S.begin(),S.end(),x)-S.begin()]);
          rep(j,2){
             //tの前後
             ll second = (j ? T[lower_bound(T.begin(),T.end(),first)-T.begin()-1] : T[upper_bound(T.begin(),T.end(),first)-T.begin()]);
             chmin(res,abs(x-first)+abs(first-second));
          }
      }
      //tの前後
      rep(i,2){
          ll first = (i ? T[lower_bound(T.begin(),T.end(),x)-T.begin()-1] : T[upper_bound(T.begin(),T.end(),x)-T.begin()]);
          rep(j,2){
             //tの前後
             ll second = (j ? S[lower_bound(S.begin(),S.end(),first)-S.begin()-1] : S[upper_bound(S.begin(),S.end(),first)-S.begin()]);
             chmin(res,abs(x-first)+abs(first-second));
          }
      }

      cout << res << endl;
  }

}
    

