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


int main()
{
  int N;
  cin >> N;
  
  string S[N];
  
  ll ABCount=0;
  ll ACount=0;
  ll BCount=0;

  rep(i,N){
      cin >> S[i];
  }
  bool flag = false;
  rep(i,N){
      rep(j,S[i].length()-1){
          if(S[i][j] == 'A' && S[i][j+1] == 'B') ABCount++;
      }
      if(S[i][0] == 'B') BCount++;
      if(S[i][S[i].length()-1] == 'A') ACount++;
      //すべてB---Aみたいになっていれば結果から-1しなければならない、環状につながない限りこの場合ABをすべて使えない
      //↓はB--or--Aならflagがtrue、B--Aならflagがfalseのまま
      if((S[i][0] == 'B' || S[i][S[i].length()-1] == 'A') && !(S[i][0] == 'B' && S[i][S[i].length()-1] == 'A')) flag=true;
  }

  ll ans=0;
  ans += ABCount;
  ans += min(ACount,BCount);
  if(!flag&&min(ACount,BCount)) ans-=1;

  fin(ans);
  
}

