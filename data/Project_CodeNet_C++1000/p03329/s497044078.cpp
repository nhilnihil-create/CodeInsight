#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using mat = vector<vector<ll>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
const int inf = 1001001001;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }

template<class T> struct edge { int to; T cost;};


int main() {
  int N; cin >>N;
  int n6=0, n9=0;
  {
    int tmp1 = N; while (tmp1 > 0){ tmp1 /= 6; n6++; }
    int tmp2 = N; while (tmp2 > 0){ tmp2 /= 9; n9++; }
  }
  // N円の範囲に収まるのは6^n6までと9^n9まで
  vector<vector<int>> dp1(n9+1, vector<int>(N+1, inf));
  dp1[0][0] = 0;
  // dp1[i][j] := i番目までの引き出し(i番目の引き出しを9^i円とする)を行い、j円引き出した時の操作の最小回数
  int buf = 1;
  for (int i=1; i<=n9; i++){
    buf *= 9;
    for (int j=0; j<=N; j++){
      chmin(dp1[i][j], dp1[i-1][j]);
      if (j-buf >= 0) chmin(dp1[i][j], dp1[i][j-buf] + 1);
    }
  }
  vector<vector<int>> dp2(n6+1, vector<int>(N+1, inf));
  for (int j=0; j<=N; j++) dp2[0][j] = dp1[n9][j];
  buf = 1;
  for (int i=1; i<=n6; i++){
    buf *= 6;
    for (int j=0; j<=N; j++){
      chmin(dp2[i][j], dp2[i-1][j]);
      if (j-buf >= 0) chmin(dp2[i][j], dp2[i][j-buf] + 1);
    }
  }
  int res = inf;
  for (int j=0; j<=N; j++){
    chmin(res, dp2[n6][j] + N-j);
  }
  cout <<res <<endl;
}
