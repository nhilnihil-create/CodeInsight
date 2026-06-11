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


int N,A,B,C;
vector<int> L;
vector<int> use;

int dfs(int v){
  if (v == N){
    int a = 0; int b = 0; int c = 0;
    int res = -30;
    rep(i, N){
      if (use[i] == 1){
        a += L[i]; res += 10;
      }else if (use[i] == 2){
        b += L[i]; res += 10;
      }else if (use[i] == 3){
        c += L[i]; res += 10;
      }
    }
    if (a == 0 || b == 0 || c == 0) return INT_MAX;
    res += abs(A - a) + abs(B - b) + abs(C - c);
    return res;
  }
  int res = INT_MAX;
  use[v] = 0; chmin(res, dfs(v+1));
  use[v] = 1; chmin(res, dfs(v+1));
  use[v] = 2; chmin(res, dfs(v+1));
  use[v] = 3; chmin(res, dfs(v+1));
  use[v] = 0;
  return res;
}

int main() {
  cin >>N >>A >>B >>C;
  L.assign(N, 0); rep(i, N) cin >>L[i];
  use.assign(N, 0); // 0:not use , 1: a, 2: b, 3: c とする
  int res = dfs(0);
  cout <<res <<endl;
}
