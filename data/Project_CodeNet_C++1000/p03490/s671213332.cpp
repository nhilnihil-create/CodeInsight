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

bool x_dp[2][40100];
bool y_dp[2][40100];

int main() {
  string s;
  cin >> s;

  int x, y;
  cin >> x >> y;

  int pos_x = 0, pos_y = 0;

  int n = s.size();

  vector<int> xv, yv;
  REP(i, n) {
    if(s[i] == 'F') pos_x++;
    else break;
  }

  int now = 1;
  int len = 0;
  for (int i = pos_x + 1; i < n; i++) {
    if (s[i] == 'F') {
      len++;
    } else {
      if(len > 0) {
        if(now == 0) xv.push_back(len); 
        else yv.push_back(len);
      }
      now = 1 - now;
      len = 0;
    }
  }
  if(len > 0) {
    if(now == 0) xv.push_back(len); 
    else yv.push_back(len);
  }

  x_dp[0][pos_x + 20000] = true;
  int x_sum = pos_x;
  REP(i, (int)xv.size()) {
    x_sum += xv[i];
    for(int j = -x_sum; j <= x_sum; j++){
      x_dp[(i + 1) % 2][j + 20000] = x_dp[i % 2][j + 20000 - xv[i]] || x_dp[i % 2][j + 20000 + xv[i]];
    }
  }

  y_dp[0][20000] = true;
  int y_sum = pos_y;
  REP(i, (int)yv.size()) {
    y_sum += yv[i];
    for(int j = -y_sum; j <= y_sum; j++){
      y_dp[(i + 1) % 2][j + 20000] = y_dp[i % 2][j + 20000 - yv[i]] || y_dp[i % 2][j + 20000 + yv[i]];
    }
  }

  Yes(x_dp[(int)xv.size() % 2][x + 20000] && y_dp[(int)yv.size() % 2][y + 20000])

  return 0;
}
