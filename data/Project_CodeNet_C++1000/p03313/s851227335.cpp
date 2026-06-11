#include <bits/stdc++.h>
#define FOR(v, a, b) for(int v = (a); v < (b); ++v)
#define FORE(v, a, b) for(int v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(int v = (a); v >= (b); --v)
#define ALL(x) (x).begin(), (x).end()
#define ITR(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)
#define RITR(it, c) for(auto it = (c).rbegin(); it != (c).rend(); ++it)
#define EXIST(c,x) ((c).find(x) != (c).end())
#define LLI long long int
#define fst first
#define snd second

#ifdef DEBUG
#include <misc/C++/Debug.cpp>
#else
#define dump(x)
#endif

#define gcd __gcd

using namespace std;
template <class T> constexpr T lcm(T m, T n){return m/gcd(m,n)*n;}

template <typename I> void join(ostream &ost, I s, I t, string d=" "){for(auto i=s; i!=t; ++i){if(i!=s)ost<<d; ost<<*i;}ost<<endl;}
template <typename T> istream& operator>>(istream &is, vector<T> &v){for(auto &a : v) is >> a; return is;}
template <typename T, typename U> istream& operator>>(istream &is, pair<T,U> &p){is >> p.first >> p.second; return is;}

template <typename T, typename U> T& chmin(T &a, const U &b){return a = (a<=b?a:b);}
template <typename T, typename U> T& chmax(T &a, const U &b){return a = (a>=b?a:b);}
template <typename T, size_t N, typename U> void fill_array(T (&a)[N], const U &v){fill((U*)a, (U*)(a+N), v);}

bool is_included_in(int a, int b){
  return (a&(~b)) == 0;
}
vector<LLI> a;

using pii = pair<int,int>;
pii g(pii &x, pii &y){
  vector<int> temp = {x.fst, y.fst};
  if(x.snd != -1) temp.push_back(x.snd);
  if(y.snd != -1) temp.push_back(y.snd);

  sort(ALL(temp), [&](int p, int q){return a[p] > a[q];});
  temp.erase(unique(ALL(temp)), temp.end());

  if(temp.size() == 1) return make_pair(temp[0], -1);
  return make_pair(temp[0], temp[1]);
}

template <typename T> void fast_zeta_transform_subset(vector<T> &f){
  for(int i=0; (1<<i) < f.size(); ++i){
    REP(j,f.size()){
      if(j & (1<<i)) f[j] = g(f[j], f[j ^ (1<<i)]);
    }
  }
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  while(cin >> N){
    a = vector<LLI>(1<<N); cin >> a;

    vector<pair<int,int>> dp(1<<N);
    REP(i,1<<N) dp[i] = make_pair(i,-1);
    fast_zeta_transform_subset(dp);

    dump(dp);
    
    LLI ans = 0;
    FOR(k,1,1<<N){
      chmax(ans, a[dp[k].fst] + a[dp[k].snd]);
      cout << ans << endl;
    }
  }
  
  return 0;
}
