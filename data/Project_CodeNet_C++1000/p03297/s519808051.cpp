#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<double> vd;
typedef vector<vd> vdd;

typedef pair<double, double> pd;
typedef vector<pd> vpd;


#define FOR(i,x,y) for(ll i=(ll)x; i<(ll)y; ++i)
#define REP(i,y) FOR(i, 0, y)
#define RFOR(i,x,y) for(ll i=(ll)x; i>=(ll)y; --i)
#define RREP(i,x) RFOR(i, x, 0)
#define ALL(a) a.begin(), a.end()
#define pb push_back
#define debug_print(x...) cerr << "line " << __LINE__ << " : "; debug_print_in(x);

template <typename First>
void debug_print_in(First first){
  cerr << first << endl;
  return;
}

template <typename First, typename... Rest>
void debug_print_in(First first, Rest... rest){
  cerr << first << " ";
  debug_print_in(rest...);
  return;
}

void IN(void){
  return;
}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){
  cin >> first;
  IN(rest...);
  return;
}

template <typename First>
void OUT(First first){
  cout << first << endl;
  return;
}

template <typename First, typename... Rest>
void OUT(First first, Rest... rest){
  cout << first << " ";
  OUT(rest...);
  return;
}

template<class t, class u> t chmax(t&a,u b){if(a<b)a=b; return a;};
template<class t, class u> t chmin(t&a,u b){if(a>b)a=b; return a;};
int popcount(int t){return __builtin_popcount(t);} //GCC
int popcount(ll t){return __builtin_popcountll(t);} //GCC

template <typename T>
void vec_print(vector<T> VEC){
  REP(i, VEC.size()){
    cerr << VEC[i] << " ";
  }
  cerr << endl;
};

template <typename T>
void mat_print(vector<vector<T> > MAT){
  REP(i,MAT.size()){
    REP(j,MAT[i].size()){
      cerr << MAT[i][j] << " ";
    }
    cerr << endl;
  }
};

constexpr int INF = (1<<30);
constexpr ll INFLL = 1LL<<62;
constexpr long double EPS = 1e-12;
constexpr ll MOD = (ll)((1E+9)+7);

ll gcd(ll x, ll y){
  if(y==0) return x;
  return gcd(y, x-(x/y)*y);
}

bool check(ll A, ll B, ll C, ll D){
  if(A<B) return false;
  if(D<B) return false;
  if(C>=B) return true;
  // A>=B>C ? D>=B
  // A+(D-B)*x - ((A+(D-B)*x-C-1)/B)*B < B?

  if(D==B){
    ll tmp = A-(A/B)*B;
    if(tmp>C) return false;
    return true;
  }

  ll tmp = gcd(D-B, B);
  ll shift = (A-C-1)%B;
  ll k = ((B-shift+tmp-1)/tmp)*tmp;
  ll tmp2 = A+k - ((k+A-C-1)/B)*B;
  //debug_print(tmp, k, A+k, k+A-C-1, B, tmp2);
  if(tmp2<B) return false;
  return true;
}

int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  ll T;
  IN(T);
  REP(i,T){
    ll A, B, C, D;
    IN(A,B,C,D);
    if(check(A,B,C,D)){
      OUT("Yes");
    }else{
      OUT("No");
    }
  }

  return 0;
}