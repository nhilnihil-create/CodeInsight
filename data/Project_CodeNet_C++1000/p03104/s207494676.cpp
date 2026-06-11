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


ll check2(ll x, int t, ll n2){
  // 2^t = n2;
  // [0, x] の整数について、t ビット目が1となるものの数を返す
  // 偶奇が大事
  if (t == 0){
    // 0 ビット目に関しては2で割った切り上げが答え
    ll buf = (x + 1) / 2;
    return buf % 2;
  }else if (t == 1){
    // 4の倍数分は01, 10, 11, 00 なので2つ塊で偶数。
    // 4で割った余りが2であれば奇数
    ll buf = x % 4;
    int res = buf == 2 ? 1 : 0;
    return res;
  }else if (t == 2){
    // 8の倍数分は001,010,011,100,101,110,111,000 なので4つ塊で偶数。
    // 8で割った余りが4,6であれば奇数
    ll buf = x % 8;
    int res = 0;
    if (buf == 4 || buf == 6) res = 1;
    return res;
  }else{
    // 2^t = n2 の倍数分は - なので2^(t-1)つ塊で偶数。
    // 2^t で割った余りが2^(t-1), 2^(t-1) + 2, 2^(t-1) + 4, ..., 2^t - 2 であれば奇数
    ll buf = x % (n2 * 2);
    if (buf < n2) return 0;
    int tmp = buf % 2;
    if (tmp == 0) return 1;
    else return 0;
  }

}

ll check(ll x, ll y, int t, ll n2){
  // t ビット目について、[x, y] の排他的論理和を求める
  // ft(x, y) みたいなやつ
  // 2^t = n2
  // 要は t ビット目が1であるものが奇数個あればn2、偶数個あれば0を返す
  if (y < n2) return 0;
  // [0, y] の個数から[0, x-1] の個数を引けば [x, y] の個数が分かる
  int buf = check2(y, t, n2) - check2(x-1, t, n2) + 100;
  buf %= 2;
  ll res = buf == 1 ? n2 : 0;
  return res;
}

int main() {
  ll A,B; cin >>A >>B;
  if (A == B){ cout <<A <<endl; return 0; }
  if (A+1 == B){ cout <<(A^B) <<endl; return 0; }
  A = A == 0 ? 1 : A;

  ll res = 0;
  ll n2 = 1;
  rep(i, 41){
    if (i > 0) n2 *= 2;
    ll tmp = check(A, B, i, n2);
    // if (tmp == -1) break;
    res += tmp;
  }
  cout <<res <<endl;
}

/*

*/
