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


int main() {
  int N; cin >>N;
  map<int,int> fact;
  for (int i=2; i<=N; i++){
    int tmp = i;
    for (int factor=2; factor<100; factor++){
      while (tmp % factor == 0){
        fact[factor]++;
        tmp /= factor;
      }
      if (tmp == 1) break;
    }
  }
  // factにはN!の素因数が全て入っている
  // 約数が75個：3*5*5 or 3*25 or 5*15 or 75
  // 乃ち、素因数分解したときの素因数の指数が
  // 2,4,4 or 2,24 or 4,14 or 74
  map<int,int> exponent;
  // 指数が2, 4, 14, 24, 74個あるものの個数を格納
  for (auto p : fact){
    int k = p.first;
    int v = p.second;
    if (v >= 2) exponent[2]++;
    if (v >= 4) exponent[4]++;
    if (v >= 14) exponent[14]++;
    if (v >= 24) exponent[24]++;
    if (v >= 74) exponent[74]++;
  }
  int res = 0;
  // 指数が74単独のヤツ
  res += exponent[74];
  // 指数が4, 14のヤツ
  res += exponent[14] * (exponent[4]-1);
  // 指数が2, 24のやつ
  res += exponent[24] * (exponent[2]-1);
  // 指数が2, 4, 4のやつ
  res += exponent[4] * (exponent[4] - 1) / 2 * (exponent[2] - 2);
  cout <<res <<endl;
}