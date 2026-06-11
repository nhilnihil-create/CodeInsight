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
  int A,B; cin >>A >>B;
  // 33*16=528
  cout <<99 <<" " <<96 <<endl;
  string tmp = "";
  rep(i, 48) tmp += ".";
  rep(i, 48) tmp += "#";
  vector<string> field(99, tmp);
  A--; B--;
  bool ok = false;
  for (int i=0; i<33; i++){
    for (int j=0; j<16; j++){
      if (B == 0) ok = true;
      if (ok) break;
      field[i*3+1][j*3+1] = '#';
      B--;
    }
    if (ok) break;
  }
  ok = false;
  for (int i=0; i<33; i++){
    for (int j=0; j<16; j++){
      if (A == 0) ok = true;
      if (ok) break;
      field[i*3+1][48+j*3+1] = '.';
      A--;
    }
    if (ok) break;
  }
  for (int i=0; i<field.size(); i++){
    cout <<field[i] <<endl;
  }
}