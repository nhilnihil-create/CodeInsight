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

int main(){
  int n;
  cin >> n;

  vector<ll> a(n),b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];

  ll ans=0;
  for(int d = 32; d >= 0; --d){
    REP(i,n) a[i] %= (1LL << (d + 1));
    REP(i,n) b[i] %= (1LL << (d + 1));
    sort(all(b));

    ll cnt = 0;
    ll cur = 1LL << d;
    REP(i,n){
      cnt += lower_bound(all(b), 4*cur-a[i]) - lower_bound(all(b), 3*cur-a[i]);
      cnt += lower_bound(all(b), 2*cur-a[i]) - lower_bound(all(b), cur-a[i]);
    }
    if(cnt % 2 == 1) ans += cur;
  }

  pl(ans)
  return 0;

}