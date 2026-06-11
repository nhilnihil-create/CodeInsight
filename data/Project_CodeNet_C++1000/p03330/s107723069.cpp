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


int main() {
  /*
  理想
  a b c a b c a b
  b c a b c a b c
  c a b c a b c a
  a b c a b c a b
  ...
  */
  int N,C; cin >>N >>C;
  vector<vector<int>> D(C, vector<int>(C, 0));
  rep(i, C) rep(j, C) cin >>D[i][j];
  // D[i][j] := 色を i から j に塗り替えるときの違和感

  vector<vector<int>> field(N, vector<int>(N, 0));
  rep(i, N) rep(j, N) cin >>field[i][j];
  rep(i, N) rep(j, N) field[i][j]--;
  // field[i][j] := 最初に(i,j) に塗られている色

  vector<vector<int>> color(3, vector<int>(C, 0));
  // color[i][j] :=
  //   同じ色で塗るべき領域は3つ。領域 i について、
  //   最初に塗られている色 j の数

  vector<vector<ll>> dif(3, vector<ll>(C, 0));
  // dif[i][j] := 
  //   領域 i について、色を j で塗ると決めた時の違和感の総和

  rep(i, N) rep(j, N) color[(i+j)%3][field[i][j]]++;
  
  rep(k, 3){
    // 領域 k について
    rep(c, C){
      // 塗る色を c に決めた時の違和感の総和を計算
      // 領域 k について、最初に塗られている色 j の数はcolor[k][j]に格納されている
      rep(j, C) dif[k][c] += (ll)color[k][j] * (ll)D[j][c];
    }
  }
  ll res = numeric_limits<ll>::max();
  rep(i, C){
    rep(j, C){
      if (i == j) continue;
      rep(k, C){
        if (i == k || j == k) continue;
        ll buf = dif[0][i] + dif[1][j] + dif[2][k];
        chmin(res, buf);
      }
    }
  }
  cout <<res <<endl;
}
