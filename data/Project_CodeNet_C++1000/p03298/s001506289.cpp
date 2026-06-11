#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
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


int main() {
  int N; cin >>N;
  string s; cin >>s;
  N *= 2;
  int n2 = N/2;
  vector<string> ps(1 << n2);
  string tmp = "";
  rep(i, n2+1) tmp += '!';
  rep(i, 1 << n2){
    int head = 0, tail = n2;
    string st = tmp;
    rep(j, n2){
      if ((i >> j) & 1) st[head++] = s[j];
      else st[tail--] = s[j];
    }
    ps[i] = st;
  }
  sort(all(ps));
  ll res = 0;
  rep(i, 1 << N-n2){
    int head = 0, tail = n2;
    string st = tmp;
    rep(j, n2){
      if ((i >> j) & 1) st[tail--] = s[N-1-j];
      else st[head++] = s[N-1-j];
    }
    int num = upper_bound(all(ps), st) - lower_bound(all(ps), st);
    res += num;
  }
  cout <<res <<endl;
}
