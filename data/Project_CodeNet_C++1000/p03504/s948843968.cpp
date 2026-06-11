#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
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
#define b_e(a) a.begin(),a.end() //sort(b_e(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll)(n) ; i++ )
#define DREP(i,m,n) for(ll i=(ll)(m) ; i > (ll)(n) ; i-- )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define p_b push_back
#define SZ(x) ((ll)(x).size()) //size()がunsignedなのでエラー避けに
#define endk '\n'


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

  ll N, C;
  cin >> N >> C;

  // [channel][<s, t>]
  vector<vector<pll> > programs(C);
  rep(i, N){
    ll s, t, c;
    cin >> s >> t >> c;
    c--; // 0-indexed

    programs[c].p_b(m_p(s, t));
  }

  // 始点で昇順ソート
  rep(c, C) sort(b_e(programs[c]));


  // 各チャンネル毎に、1秒も空けずに連続している番組は1つの番組とみなす
  vector<pll> cmp_pgs;

  rep(c, C){
    // 今保持している番組
    ll nows = -1;
    ll nowt = -1;

    for (pll eachp : programs[c]){
      ll s = eachp.first;
      ll t = eachp.second;
      if (nows == -1){
        nows = s;
        nowt = t;
      }
      else{
        // 今保持している番組がある
        if (nowt == s){
          // 番組を連結 nowsはそのままで、nowtは新しい番組の終了時間
          nowt = t;
        }
        else{
          // 番組が連続していないので、別の番組とみなす
          cmp_pgs.p_b(m_p(nows, nowt));
          nows = s;
          nowt = t;
        }
      }
    }
    // 最後に残った番組を cmp_pgs に入れる
    // ただし、一つも番組が無かった場合は -1, -1 になっているので、弾く
    if (nows != -1) cmp_pgs.p_b(m_p(nows, nowt));
  }


  // これで、チャンネルのことは考えなくてよくなった
  //  = [s, t) を占有する番組はなく、全ての番組が、[s, t] を占有する

  // 同じ時間にいくつ番組がかぶっているかを計算し、その最大値と同じ数の録画機を用意すればいい

  // imos法

  
  vector<ll> imos(100002, 0);
  ll len = SZ(cmp_pgs);

  rep(i, len){
    ll s = cmp_pgs[i].first;
    ll t = cmp_pgs[i].second;
    imos[s]++;
    imos[t+1]--;
  }
  // imos[0] は必ず0
  ll max_overlap = 0;
  rep(i, SZ(imos)-1){
    imos[i+1] = imos[i] + imos[i+1];
    chmax(max_overlap, imos[i+1]);
  }

  cout << max_overlap << endk;

}