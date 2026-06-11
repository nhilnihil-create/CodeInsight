#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (V)) cout <<x <<" " <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
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


int dist(int x1,int y1,int x2,int y2){
  // マンハッタン距離？を返す
  return abs(x1-x2) + abs(y1-y2);
}

int check(int i,int j,vector<int> &X,vector<int> &Y,vector<int> &H,int N){
  // 座標(j,i)について、全ての条件を満たすようなピラミッドの高さがあるかをチェック
  int res = 0;
  int buf = INT_MAX;
  rep(qq,N){
    int x = X[qq], y = Y[qq], h = H[qq];
    // (x,y)の高さがhである
    if (h > 0){
      // 高さがhであれば(j,i)からの距離を足せばそのまま(j,i)の高さになる
      if (res == 0) res = h + dist(j,i,x,y);
      if (res != h + dist(j,i,x,y)) return 0;
    }else{
      // 高さが0であれば(j,i)からの距離(を足したもの)が高さの最大値になる(それより大きくなることはない)
      chmin(buf, dist(j,i,x,y));
      if (res > buf) return 0;
    }
  }
  return res;
}

int main() {
  int N; cin >>N;
  vector<int> x(N),y(N),h(N);
  rep(i, N) cin >>x[i] >>y[i] >>h[i];
  for (int i=0; i<=100; i++){
    for (int j=0; j<=100; j++){
      // 各々の座標(j,i)とかについて条件が合っているかをチェック
      // 全ての条件を満たしていればそれが答え
      int height = check(i,j,x,y,h,N);
      if (height){
        cout <<j <<" " <<i <<" " <<height <<endl;
      }
    }
  }
}