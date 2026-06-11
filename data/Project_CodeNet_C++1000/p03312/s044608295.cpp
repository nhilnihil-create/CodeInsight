bool DBG = false;
#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

//#include <boost/multiprecision/cpp_dec_float.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
using ld = long double;
//using i128 = __int128_t;
//using bint = boost::multiprecision::cpp_int
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
//constexpr ll mod =  1'000'000'007;
constexpr ll mod = 998244353;


int f(int n){
  int ret = 0;
  int i = 1;
  for(;i*i<n;++i){
    if(n%i==0) ret += 2;
  }
  if(i*i==n) ++ret;
  return ret;
}




void solve(){
  int n; cin >> n;
  V<ll> a(n); cin >> a;
  V<ll> sum(n+1);
  FOR(i,0,n) sum[i+1] = sum[i] + a[i];
  if(n < 100 ){
    ll ans = LINF;
    FOR(s1,1,n+1){
      FOR(s2,s1+1,n+1){
        FOR(s3,s2+1,n+1){
          ll tmp = max<ll>({abs(sum[n]-sum[s3]),abs(sum[s3]-sum[s2]), abs(sum[s2]-sum[s1]),abs(sum[s1]-sum[0]) }) - min<ll>({abs(sum[n]-sum[s3]),abs(sum[s3]-sum[s2]), abs(sum[s2]-sum[s1]),abs(sum[s1]-sum[0]) });
          ans = min<ll>(tmp,ans);
        }
      }
    }
    couts( ans );
    return;
  }
  //FOR(i,0,n) couts( abs( (sum[n]-sum[i]) - (sum[i]-sum[0])  ) ); return;
  auto f = [&](int L, int R)->pair<ll,ll>{
    pair<ll,ll> ret;
    ll l = L, r = R, m;
    while(r-l>1){
      m = (r+l)/2;
      if(2*sum[m]<=sum[L]+sum[R] ) l = m;
      else r = m;
    }
    if( abs(2*sum[l]-sum[L]-sum[R]) < abs(2*sum[r]-sum[L]-sum[R]) 
       ||  (abs(2*sum[l]-sum[L]-sum[R]) == abs(2*sum[r]-sum[L]-sum[R]) )    ) {
         ret.fs = sum[R] - sum[l];
         ret.sd = sum[l] - sum[L];
         
    }
    else{
      ret.fs = sum[R]-sum[r];
      ret.sd = sum[r]-sum[L];
    }
    if(ret.fs<ret.sd) swap(ret.fs,ret.sd);
    return ret;
  };
  ll ans = LINF;
  FOR(i,2,n-1){// [0,i) [i,n)
    pair<ll,ll> r1 = f(0,i), r2=f(i,n);
    ll tmp = max<ll>(r1.fs,r2.fs) - min<ll>(r1.sd,r2.sd);
    ans = min<ll>(ans,tmp);
  }
  couts( ans );
  
}




int main(void){
  //std::cout << std::fixed << std::setprecision(20);
  cin.tie(0);
  //ios::sync_with_stdio(false);
  solve();
  //printf("%s", outst);
  return 0;
}


