bool DBG = false;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
using ld = long double;
//using i128 = __int128_t;
using bint = boost::multiprecision::cpp_int;
//using d1024 = boost::multiprecision::number<mp::cpp_dec_float<1024>>;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=((b)-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define fs first
#define sd second
#define couts(x) cout << (x) << (" ")
#define coutn(x) cout << (x) << ("\n")
#define ncouts(x) numout(x),outst[outst_N++] = ' '
#define ncoutn(x) numout(x),outst[outst_N++] = '\n'
#define scouts(x) strout(x),outst[outst_N++] = ' '
#define scoutn(x) strout(x),outst[outst_N++] = '\n'
#define dcouts(x) if(DBG) couts(x)
#define dcoutn(x) if(DBG) coutn(x)
#define endl "\n"
#define psb push_back
#define ppb pop_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define LBIT(x,a) (((x)>>(a))&1LL)
#define IBIT(x,a) (((x)>>(a))&1)
#define BCOUNT(x) (__builtin_popcount(x))
template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T1, typename T2> std::istream &operator>>(std::istream &is, std::pair<T1,T2> &p){is >> p.first >> p.second; return is; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::deque<T> &vec){ os << "deque["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> std::ostream &operator<<(std::ostream &os, const std::map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> std::ostream &operator<<(std::ostream &os, const std::unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
/*
std::ostream &operator<<(std::ostream &os, const i128 nu){
  i128 co = nu;
  if(co==0){cout << '0';}
  else{
    string ous; if(co<0){cout<<'-'; co*=-1;}
    while(co){
      ous += (co%10)+'0';
      co /= 10;
    }
    reverse(ALL(ous));
    cout<<ous;
  }
  return os;
}
std::istream &operator>>(std::istream &is, i128 &nu){ string cs; cin >> cs; nu=0;int mn=1; for(auto &x:cs) { if(x!='-'){nu*=10;nu+=(x-'0');} else mn *= -1;} nu *= mn;  return is; }

*/


template<class T> using V = vector<T>;
template<class T> using V2 = V<V<T>>;
template<class T> using V3 = V<V2<T>>;
template<class T> using V4 = V<V3<T>>;


char outst[20'000'000]; int outst_N = 0;
char outst_tmp[200];
template<class NUM >
void numout(NUM n){
  if(n<0) { n*=-1; outst[outst_N++] = '-';}
  if(n==0){ outst[outst_N++] = '0'; return;}
  int cnt = 0;
  while(n>0){
    outst_tmp[cnt++] = '0' + (n % 10);
    n /= 10;
  }
  IFOR(i,0,cnt){
    outst[outst_N++] = outst_tmp[i];
  }
}
void strout(std::string s){
  for(auto x: s){
    outst[outst_N++] = x;
  }
}

constexpr ll LINF = 1LL << 60;
constexpr int IINF = 1 << 28;
constexpr ll mod =  1'000'000'007;
//constexpr ll mod = 998244353;


template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;
  
  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, seg[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};


void solve(){
  int n, k, q; cin >> n >> k >> q;
  V<ll> a(n); cin >> a;
  map<int,ll> mp; map<int, set<int>> place;
  {
    set<ll> aset; map<ll,int> mp2;
    FOR(i,0,n) aset.insert(a[i]);
    int cnt = 1;
    for(auto x:aset){
      mp[cnt] = x;
      mp2[x] = cnt;
      ++cnt;
    }
    cnt = 0;
    for(auto &x:a){
      x = mp2[x];
      place[x].insert(cnt);
      ++cnt;
    }
  }
  
  //coutn( a );
  //coutn( mp);
  //coutn( place );
  
  
  ll ans = LINF;
  FOR(i,0,n+1-q){
    //break;
    ll mx = -LINF, mn = LINF; int q_ = q;
    
    SegmentTree< int > sgt(n+5,[](int a, int b)->int{return a+b;},0);
    V<int> ad(n);
    FOR(j,0,n) ad[j] = a[j];
    
    int cur = i+1;
    while(cur<=place.size() && q_>0){
      for(auto x: place[cur]){
        int R=x, L=x;
        while(R+1<n && ad[R+1]>=ad[x]) ++R;
        while(L-1>=0 && ad[L-1]>=ad[x]) --L;
        //couts(i); couts(cur);couts(L); couts(R); coutn( sgt.query(L,R+1) );
        if(R-L+1-sgt.query(L,R+1) >=k){
          --q_;
          mx = max(mx,mp[cur]);
          mn = min(mn,mp[cur]);
          sgt.update(x,1);
          ad[x] = IINF;
        }
        if(q_==0) break;
      }
      ++cur;
    }
    
    
    if(q_==0 && (mx-mn)<LINF ) ans = min(ans, mx-mn);
    //couts(mx); coutn(mn);
  }
  cout << ans;
  
}






int main(void){
  //std::cout << std::fixed << std::setprecision(20);
  cin.tie(0);
  //ios::sync_with_stdio(false);
  solve();
  //printf("%s", outst);
  return 0;
}


