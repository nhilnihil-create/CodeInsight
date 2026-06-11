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


int N;
vector<vector<int>> F;
vector<vector<ll>> P;

void input() {
  cin >>N;
  F.assign(N, vector<int>(10, 0));
  rep(i, N) rep(j, 10) cin >>F[i][j];
  P.assign(N, vector<ll>(11, 0));
  rep(i, N) rep(j, 11) cin >>P[i][j];
}

int main() {
  input();
  ll res = -10000000000000000;
  for (int S=1; S<(1<<10); S++){
    // joisino店が開いている時間帯の集合
    ll resS = 0;
    for (int i=0; i<N; i++){
      // 各々の店について両方が営業している時間帯の個数をカウント
      int cnt = 0;
      for (int d=0; d<10; d++) if ((S & (1<<d)) && F[i][d]) cnt++;
      resS += P[i][cnt];
    }
    chmax(res, resS);
  }

  cout <<res <<endl;
}