#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define allR(v) v.rbegin(), v.rend()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
typedef pair<int,int> Pi;
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

int N,M;
vector<ll> X,Y,Z;

void vecOperate(vector<ll> &a, int p){
  // pの1の位が1なら全て-1倍する
  p %= 2;
  if (p == 1){
    rep(i, a.size()) a[i] *= -1;
  }
}

ll dping(vector<ll> &X, vector<ll> &Y, vector<ll> &Z, int p){
  vecOperate(X, p>>2);
  vecOperate(Y, p>>1);
  vecOperate(Z, p);
  vector<vector<ll>> dp(N+1, vector<ll>(M+1, -1001001001001001));
  dp[0][0] = 0;
  // dp[i][j] := i個からj個を選んだときのうれしさの最大値
  // ここでは各々の値の和の最大値として考え、その最大値を返す
  for (int i=0; i<N; i++){
    for (int j=0; j<=M; j++){
      chmax(dp[i+1][j], dp[i][j]);
      if (j < M) chmax(dp[i+1][j+1], dp[i][j] + X[i] + Y[i] + Z[i]);
    }
  }
  ll res = dp[N][M];
  vecOperate(X, p>>2);
  vecOperate(Y, p>>1);
  vecOperate(Z, p);
  return res;
}

int main() {
  cin >>N >>M;
  X.assign(N, 0); Y.assign(N, 0); Z.assign(N, 0);
  rep(i, N) cin >>X[i] >>Y[i] >>Z[i];
  ll res = 0;
  rep(i, 8) chmax(res, dping(X, Y, Z, i));
  cout <<res <<endl;
}
