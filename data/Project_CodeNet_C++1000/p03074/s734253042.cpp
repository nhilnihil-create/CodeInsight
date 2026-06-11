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
  int N,K; cin >>N >>K;
  string s; cin >>s;
  vector<int> A;
  int buf = 1;
  for (int i=1; i<=N; i++){
    if (i < N && s[i] == s[i-1]) buf++;
    else{
      int coe = s[i-1] == '0' ? -1 : 1;
      A.push_back(coe * buf);
      buf = 1;
    }
  }
  // Aには'0'の数を負の数、'1'の数を正の数として並んでいる
  int n = A.size();
  int i = 0, j = 0; // [i, j)
  int tatsu = 0;
  int sum = 0;
  int res = 0;
  while (j < n){
    if (A[j] > 0){
      sum += A[j]; j++;
    }
    if (A[j] < 0){
      if (tatsu < K){
        tatsu++;
        sum += abs(A[j]); j++;
      }else{
        chmax(res, sum);
        if (A[i] > 0){ sum -= A[i]; i++; }
        sum -= abs(A[i]); i++;
        sum += abs(A[j]); j++;
      }
    }
    if (j == n){
      chmax(res, sum); break;
    }
  }
  cout <<res <<endl;
}