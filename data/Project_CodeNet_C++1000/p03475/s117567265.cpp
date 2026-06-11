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
vector<ll> C, S, F;

void input() {
  cin >>N;
  C.assign(N-1, 0); S.assign(N-1, 0); F.assign(N-1, 0);
  rep(i, N-1) cin >>C[i] >>S[i] >>F[i];
}

int main() {
  input();
  for (int start=0; start<N; start++){
    ll res = 0;
    for (int i=start; i<N-1; i++){
      // 今は駅iにいます。次の駅i+1に進みたいです
      if (res <= S[i]){
        // 最初の列車がまだなら最初の列車に乗ります
        res = S[i] + C[i];
      }else{
        // 最初の列車が既に発射しているなら次のF[i]で割り切れる時間に列車に乗ります
        if (res % F[i] == 0) res = res + C[i];
        else res = ( (res / F[i]) + 1 ) * F[i] + C[i];
      }
    }
    cout <<res <<endl;
  }
}