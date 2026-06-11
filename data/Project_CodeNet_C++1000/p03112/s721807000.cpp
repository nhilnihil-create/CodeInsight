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
  int a,b,q; cin >>a >>b >>q;
  vector<ll> s(a), t(b);
  rep(i, a) cin >>s[i];
  rep(i, b) cin >>t[i];
  rep(qq,q){
    ll x; cin >>x;
    // 地点 x から左右に近いもの各々が神社、寺の訪れるものの候補
    // 但し地点 x に丁度存在するときはややこしそう
    int s1,t1,s2,t2;
    if (lower_bound(all(s), x) == s.end()){
      // x 以上には神社は存在しない
      s1 = lower_bound(all(s), x) - s.begin() - 1;
      s2 = s1;
    }else{
      s2 = lower_bound(all(s), x) - s.begin(); // x 以上で一番近い神社のindex
      // s2 の地点が丁度 x だったり、s2より前の地点が存在しなければs1 = s2
      if (s2 == 0 || s[s2] == x) s1 = s2;
      else s1 = s2-1;
    }
    if (lower_bound(all(t), x) == t.end()){
      t1 = lower_bound(all(t), x) - t.begin() - 1;
      t2 = t1;
    }else{
      t2 = lower_bound(all(t), x) - t.begin(); // x 以上で一番近い寺のindex
      if (t2 == 0 || t[t2] == x) t1 = t2;
      else t1 = t2-1;
    }
    // 特殊な条件を除き、s1,s2は神社に関して、t1,t2は寺に関して、
    // 各々x以下、x以上で一番近い地点のindexを表す
    // とりあえず(s1,s2)*(t1,t2)を全部調べればいい
    ll res = 1000000000000000;
    int ss,tt;
    rep(i, 2){ rep(j, 2){
      ss = i == 0 ? s1 : s2;
      tt = j == 0 ? t1 : t2;
      // s[ss]とt[tt]を両方回るのに必要な移動距離は
      ll buf = abs(s[ss] - t[tt]); // 神社⇔寺
      buf += min(abs(x - s[ss]), abs(x - t[tt])); // 神社または寺の近い方にたどり着く
      chmin(res, buf);
    }}
    cout <<res <<endl;
  }
}
