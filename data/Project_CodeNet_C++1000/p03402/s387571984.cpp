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

int dx[] = {1,-1,0, 0};
int dy[] = {0,0,1,-1};
int dx2[] = {0,2,0, 2};
int dy2[] = {0,0,2,2};

int MH = 100, MW = 100;

void solve(){
  int a, b; cin >> a >> b;
  int t = (a<b);
  if(t) swap(a, b);
  couts(MH); coutn(MW);
  V2<int> c(MH, V<int>(MW));
  V2<int> used(MH, V<int>(MW));
  --b;
  used[0][0] = 1;
  FOR(i,0,MH/2){
    FOR(j,0,MW/2){
      c[2*i][2*j] = 1;
      --a;
    }
  }
  
  if(b>0){
    FOR(i,0,MH/2-1){
      FOR(j,0,MW/2-1){
        if(b>0){
          //if(i==0 && j==0)a += 3;
          //else a += 2;
          {
            int unuse = 0;
            FOR(k,0,4) unuse += (used[2*i+dx2[k] ][2*j+dy2[k] ]==0);
            a += unuse;
          }
          b--;
          FOR(k,0,4){
            c[2*i+1+dx[k] ][2*j+1+dy[k] ] = 1;
            used[2*i+1+dx[k] ][2*j+1+dy[k] ] = 1;
          }
          FOR(k,0,4){
            c[2*i+dx2[k] ][2*j+dy2[k] ] = 1;
            used[2*i+dx2[k] ][2*j+dy2[k] ] = 1;
          }
        }
        else break;
        
        
      }
      if(b<=0) break;
    }
  }
  
  
  if(a<0 ){
    
    IFOR(i,0,MH/2){
      IFOR(j,0,MW/2){
        if(a<0){
          if(!used[2*i][2*j] ) c[2*i][2*j] = 0, ++a;
        }
        else break;
      }
      if(a>=0) break;
    }
  }
  
  FOR(i,0,MH){
    FOR(j,0,MW){
      if( c[i][j]^t ){
        cout << '.';
      }else{
        cout << '#';
      }
    }
    cout << '\n';
  }
  
}






int main(void){
  //std::cout << std::fixed << std::setprecision(20);
  cin.tie(0);
  //ios::sync_with_stdio(false);
  solve();
  //printf("%s", outst);
  return 0;
}


