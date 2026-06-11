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


// 約数の列挙O(√n)--------------------------------------------
vector<int> divisor(int n){
  vector<int> res;
  for (ll i=1; i*i<=n; i++){ if (n%i==0){ res.push_back(i); if (i != n/i) res.push_back(n/i); } }
  return res;
}

int main() {
  int N,M; cin >>N >>M;
  // 最良だとai = M/N でこれが最大公約数になる
  // 乃ち答えの範囲は 1 <= x <= M/N
  // この範囲のxにおいて、M - x * N が全ai = x としたときの余っている和で、これもxの倍数であるときのみxが公約数になりうる
  // 以上より、求める値は「1<=x<=M/N かつ (M - x*N) % x == 0 を満たすxの最大値」となる
  // …が、2つ目の条件⇔xはMの約数
  // 以上より、求める値は「1<=x<=M/N を満たすMの約数xの最大値」である

  int res = 1;
  for (ll i=1; i*i<=M; i++){
    if (M%i==0){
      // i と M/i はMの約数。M/iの方からチェック
      int x = M/i;
      if (x <= M/N){
        res = x; break;
      }else if (i <= M/N){
        res = i;
      }
    }
  }
  cout <<res <<endl;
}