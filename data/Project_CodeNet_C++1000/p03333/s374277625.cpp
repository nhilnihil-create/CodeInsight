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

ll N;
vpll LR, RL;
vll L, R;

ll check1(bool init_flag){
  vb flag(N, false);
  ll count = 0;
  ll posR = 0;
  ll posL = 0;
  ll pos = 0;
  ll ans = 0;
  if(init_flag){
      while(flag[RL[posR].second]) posR++;
      ll index = RL[posR].second;
      flag[index] = true;
      count++;
      if(pos<=L[index]){
        ans += L[index]-pos;
        pos = L[index];
      }else if(R[index]<=pos){
        ans += pos-R[index];
        pos = R[index];
      }
      //debug_print(L[index], R[index], count);
  }
  while(count<N){
    {
      while(flag[LR[posL].second]) posL++;
      ll index = LR[posL].second;
      flag[index] = true;
      count++;
      if(pos<=L[index]){
        ans += L[index]-pos;
        pos = L[index];
      }else if(R[index]<=pos){
        ans += pos-R[index];
        pos = R[index];
      }
      //debug_print(L[index], R[index], count);
    }
    if(count>=N) break;
    {
      while(flag[RL[posR].second]) posR++;
      ll index = RL[posR].second;
      flag[index] = true;
      count++;
      if(pos<=L[index]){
        ans += L[index]-pos;
        pos = L[index];
      }else if(R[index]<=pos){
        ans += pos-R[index];
        pos = R[index];
      }
      //debug_print(L[index], R[index], count);
    }
  }
  return ans+abs(pos);
}

int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  IN(N);
  L.resize(N);
  R.resize(N);
  LR.resize(N);
  RL.resize(N);
  REP(i,N){
    IN(L[i], R[i]);
    LR[i].first = L[i];
    RL[i].first = R[i];
    RL[i].second = i;
    LR[i].second = i;
  }

  vb used(N, false);

  sort(ALL(RL));
  sort(ALL(LR));
  reverse(ALL(LR));

  OUT(max(check1(false), check1(true)));

  return 0;
}
