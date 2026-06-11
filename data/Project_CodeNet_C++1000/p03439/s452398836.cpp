#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=9223372036854775807;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld EPS = 1e-10; //微調整用（EPSより小さいと0と判定など）

int ii() { int x; if (scanf("%d", &x)==1) return x; else return 0; }
long long il() { long long x; if (scanf("%lld", &x)==1) return x; else return 0; }
string is() { string x; cin >> x; return x; }
char ic() { char x; cin >> x; return x; }
void oi(int x) { printf("%d ", x); }
void ol(long long x) { printf("%lld ", x); }
void od_nosp(double x) { printf("%.15f", x); } // 古い問題用
void od(double x) { printf("%.15f ", x); }
// long doubleで受け取り、fをLfなどに変えて出力すると、変な数値が出る
// それをなんとかするには独自の出力を作らなければならなそう
void os(const string &s) { printf("%s ", s.c_str()); }
void oc(const char &c) { printf("%c ", c); }
#define o_map(v){cerr << #v << endl; for(const auto& xxx: v){cout << xxx.first << " " << xxx.second << "\n";}} //動作未確認
void br() { putchar('\n'); }

// #define gcd __gcd //llは受け取らない C++17~のgcdと違うので注意
// int lcm(int a, int b){return a / gcd(a, b) * b;}
#define begin_end(a) a.begin(),a.end() //sort(begin_end(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll) (n) ; i++ )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define p_b push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに


// coutによるpairの出力（空白区切り）
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << " " << p.second << ")";}
// coutによるvectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << " "; //"\t"に変えるとTabで見やすく区切る
  }
  return s;
}
// coutによる多次元vectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i] << endl;
  }
  return s;
}

//最大値、最小値の更新。更新したor等しければtrueを返す
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}

//4近傍（上下左右） rep(i, 2) にすると右・下だけに進む
vector<int> dx_4 = {1, 0, -1, 0};
vector<int> dy_4 = {0, 1, 0, -1};

// -------- template end - //


// - library ------------- //




// --------- library end - //


int main(){

  ll N = il();

  ll left_min = 0;
  // 残っている席のうち、最も数字が小さいもの
  // 初期は0であり、だんだん変わっていくことがある
  // クエリ1以降、常に、left_minに座っている人の性別は判明している（そうでないと切り替わらない
  string left_min_s; // left_minに座っている人の性別

  // まずは席0にクエリを飛ばす
  cout << 0 << endl;
  cin >> left_min_s;
  if (left_min_s == "Vacant") return 0;

  // 次は真ん中にクエリを飛ばす
  ll q = (0 + N-1) / 2;
  cout << q << endl;
  string q_s;
  cin >> q_s;
  if (q_s == "Vacant") return 0;

  // 0~q（区間数q+1） に V が含まれるか？ q~0 に含まれるか？
  // 区間数が奇数なのに人[0]と人[q]が入れ替わっていたら0~q側にいる
  //                 そうでなければq~0 側にいる
  // 区間数が偶数なのに人[0]と人[q]が入れ替わっていたらq~0側にいる
  //                 そうでなければ0~q 側にいる
  ll left_max;
  string left_max_s;
  if ((q+1)%2==1){
    if (left_min_s != q_s){
      // 0~q側にいる
      left_max = q;
      left_max_s = q_s;
      left_min = 0; // 変わらない
      left_min_s = left_min_s; // 変わらない
    }
    else{
      // q~0側にいる
      left_max = N; // 0席目のことを、都合上、N席目とみなす
      left_max_s = left_min_s;
      left_min = q;
      left_min_s = q_s;
    }
  }
  else{
    if (left_min_s == q_s){
      // 0~q側にいる
      left_max = q;
      left_max_s = q_s;
      left_min = 0; // 変わらない
      left_min_s = left_min_s; // 変わらない
    }
    else{
      // q~0側にいる
      left_max = N; // 0席目のことを、都合上、N席目とみなす
      left_max_s = left_min_s;
      left_min = q;
      left_min_s = q_s;
    }
  }

  rep(i, 18){
    q = (left_min + left_max) / 2; // クエリで投げる番号を決める
    cout << q << endl;

    cin >> q_s;
    if (q_s == "Vacant") return 0;

    // min~q（区間数q-min+1） に V が含まれるか？ q~max に含まれるか？
    // 区間数が奇数なのに人[min]と人[q]が入れ替わっていたら0~q側にいる
    //                 そうでなければq~0 側にいる
    // 区間数が偶数なのに人[min]と人[q]が入れ替わっていたらq~0側にいる
    //                 そうでなければ0~q 側にいる
    if ((q-left_min+1)%2==1){
      if (left_min_s != q_s){
        // min~q側にいる
        left_max = q;
        left_max_s = q_s;
        left_min = left_min; // 変わらない
        left_min_s = left_min_s; // 変わらない
      }
      else{
        // q~max側にいる
        left_max = left_max; // 変わらない
        left_max_s = left_max_s;
        left_min = q;
        left_min_s = q_s;
      }
    }
    else{
      if (left_min_s == q_s){
        // min~q側にいる
        left_max = q;
        left_max_s = q_s;
        left_min = left_min; // 変わらない
        left_min_s = left_min_s; // 変わらない
      }
      else{
        // q~max側にいる
        left_max = left_max; // 変わらない
        left_max_s = left_max_s;
        left_min = q;
        left_min_s = q_s;
      }
    }
  }



}