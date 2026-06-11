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


int magic(int x, vector<int> &l, vector<bool> &use){
  // 竹の集合l と どれを使用するかの情報 use から
  // 目標 x の竹にするためにどれだけの魔力を必要とするか計算
  // 但し l のサイズと use のサイズは同じとする
  int res = -10;
  int take = 0;
  rep(i, l.size()){
    if (use[i]){
      take += l[i];
      res += 10;
    }
  }
  if (res == -10) return 100000000;
  res += abs(take - x);
  return res;
}

int main() {
  int N,A,B,C; cin >>N >>A >>B >>C;
  vector<int> L(N); rep(i, N) cin >>L[i];
  int res = INT_MAX;
  // まず、使用する全体の竹を選ぶ
  vector<bool> use(N, false);
  vector<int> Labc;
  vector<bool> usea;
  vector<int> Lbc;
  vector<bool> useb;

  for (int S=1; S<(1<<N); S++){
    // 256通り以下
    use.assign(N, false);
    for (int i=0; i<N; i++) if (S & (1<<i)) use[i] = true;

    // 使用する竹が3本未満なら無理なので確認
    int num = 0;
    rep(i, N) num += use[i];
    if (num < 3) continue;

    // 選んだnum(<=8)本の竹からA,B,Cを生成したい
    Labc.assign(num, 0); // 使用するnum本の竹を格納
    {
      int ai = 0;
      rep(i, N) if (use[i]) Labc[ai++] = L[i];
    }

    // Aに使用する竹を選ぶ
    for (int Sa=1; Sa<(1<<num); Sa++){
      // 256通り以下
      usea.assign(num, false);
      for (int i=0; i<N; i++) if (Sa & (1<<i)) usea[i] = true;
      int resa = magic(A, Labc, usea);

      int numbc = num;
      rep(i, num) numbc -= usea[i];

      // 残りnumbc本からBとCを生成する
      Lbc.assign(numbc, 0); // BとCで使用するnumbc本の竹を格納
      {
        int ai = 0;
        rep(i, num) if (!usea[i]) Lbc[ai++] = Labc[i];
      }

      for (int Sb=1; Sb<(1<<numbc); Sb++){
        useb.assign(numbc, false);
        rep(i, numbc) if (Sb & (1<<i)) useb[i] = true;
        int resb = magic(B, Lbc, useb);
        rep(i, numbc) useb[i] = useb[i] ^ true;
        int resc = magic(C, Lbc, useb);
        chmin(res, resa + resb + resc);
      }
    }
  }
  cout <<res <<endl;
}
