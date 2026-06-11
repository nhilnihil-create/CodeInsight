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

  ll H, W;
  cin >> H >> W;

  vector<vector<bool> > isOdd(H, vector<bool>(W, false));
  ll odds = 0; // 奇数の数
  rep(h, H) rep(w, W){
    ll a = il();
    if (a % 2 == 1){
      odds++;
      isOdd[h][w] = true;
    }
  }

  vector<vector<ll> > anss;

  // 奇数が1個か0個になったら終わり
  ll now_h = 0;
  ll now_w = 0;
  bool haveCoin = ( isOdd[0][0] ? true : false );
  while (odds > 1){
    // コインを持っていても持っていなくても、次のセルに移る
    // その際、偶数行なら右に、奇数行なら左に行く
    // はみでる時は下に降りる
    ll next_h = now_h;
    ll next_w = now_w + ( now_h % 2 == 0 ? 1 : -1);
    if (next_w > W-1 || next_w < 0){
      next_h += 1;
      next_w = now_w;
    }

    if (haveCoin){
      // コインを持っていたので、そこに置く 1-indexedに直す！！
      anss.p_b(vector<ll>{now_h+1, now_w+1, next_h+1, next_w+1});
      // そのセルが偶数だった場合、またコインを持つ
      // 奇数だった場合は、コインを再度持たなくていい
      if (isOdd[next_h][next_w]){
        // oddsが2つ解消した
        haveCoin = false;
        odds -= 2;
      }
    }
    else{
      // コインを持っていなかった場合
      // セルが奇数だった場合は、そのコインを拾う
      // 最後のコインであっても、拾ったあと自動でループを抜けるからOK
      if (isOdd[next_h][next_w]) haveCoin = true;
    }
    now_h = next_h;
    now_w = next_w;
  }

  cout << anss.size() << endl;
  for (auto ans : anss) cout << ans << endl;


}