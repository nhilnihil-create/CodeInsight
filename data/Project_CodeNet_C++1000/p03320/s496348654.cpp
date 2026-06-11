#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}

template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}


const int MOD = 1000000007;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;

void addM(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void mulM(long long &a, long long b) {
    a = ((a%MOD)*(b%MOD))%MOD ;
}

ll f(ll n) {
  ll res = 0;
  while (n > 0) {
    res += n%10;
    n /= 10;
  }
  return res;
}

double g(ll n) {
  return (double)(n)/f(n);
}

int main() {
  vector<ll> res;
  ll base = 1;

  for (int i = 0; i < 15; ++i) {
    for (int j = 1; j < 150; ++j) {
      res.push_back(base * (j+1) - 1);
    }
    base *= 10;
  }
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());

  for (long long i = 0; i < res.size(); ++i) {
    for (long long j = i+1; j < res.size(); ++j) {
      if (g(res[i]) > g(res[j])) {
        res.erase(res.begin() + i--);
        break;
      }
    }
  }

  long long K;
  cin >> K;

  for (long long i = 0; i < K; ++i) {
    cout << res[i] << endl;
  }

  return 0;
}