#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<assert.h>
#include<string>
#include<cstdlib>
#include<cctype>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};

// intやllをstringに変換
template<typename T> inline string toString(const T &a){
  ostringstream oss;
  oss << a;
  return oss.str();
};
// ----------------------------------------------------------------------------


int main(){
  int N;
  cin >> N;
  vector<double> l(N+2),r(N+2),v(N+2);
  l[0] = 0.0;
  r[0] = 0.0;
  v[0] = 0.0;
  double T_sum = 0;
  for(int i=1; i<=N; i++){
    int T;
    cin >> T;
    l[i] = T_sum;
    T_sum += T;
    r[i] = T_sum;
  }
  for(int i=1; i<=N; i++){
    cin >> v[i];
  }
  cerr << T_sum << endl;
  l[N+1] = T_sum;
  r[N+1] = T_sum;
  v[N+1] = 0.0;
  double ans = 0.0;
  double v_pre = 0.0;
  for(double a=0.50; a<=T_sum; a+=0.50){
    double v_now = INF;
    for(int i=0; i<=N+1; i++){
      if(a < l[i]){
        chmin(v_now, v[i]+(l[i]-a));
      }else if(r[i] < a){
        chmin(v_now, v[i]+(a-r[i]));
      }else{
        chmin(v_now, v[i]);
      }
    }
    ans += 0.2500*(v_pre + v_now);
    v_pre = v_now;
    // cerr << fixed << setprecision(10) << ans << endl;
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
