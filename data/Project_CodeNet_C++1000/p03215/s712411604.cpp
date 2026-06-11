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
#define begin_end(a) a.begin(),a.end() //sort(begin_end(vec));
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


//桁数を返す
ll GetDigit(ll num){
    ll digit=0;
    while(num!=0){
        num /= 2;
        digit++;
    }
    return digit;
}


// --------- library end - //


int main(){

  ll N, K;
  cin >> N >> K;

  vector<ll> as;
  rep(i, N){
    as.push_back(il());
  }

  priority_queue<ll> pq;
  // [l, r] の美しさ
  rep(l, N){
    // l : 0 ~ N-1
    ll tmp = 0;
    REP(r, l, N){
      // r : l ~ N-1
      tmp += as[r];
      pq.push(tmp);
    }
  } 

  // できるだけ左の桁のbitが立っているものを貪欲にとっていきたい

  // まず、立っている中で最も左のbitは何桁目か？
  ll biggest_d = GetDigit(pq.top());

  // 立てることができたbitを管理する配列
  // 添字注意 bits[d] := 右から d+1 桁目が立っていることを表す
  vector<bool> bits(biggest_d, false);

  DREP(d, biggest_d-1, -1){
    // d : biggest_d-1 ~ 0
    
    // d+1 桁目を立てようとする
    // この時、pqの一番上からK個を取って、全て d+1 桁目が立っていれば採用すればいい
    // 立っていなければ、それより下も立っていないので、その桁は諦める
    // 取った数字について、その桁をもう一度見ることはないので、その桁を折って入れる
    ll picked = 0;
    vector<ll> picked_num;
    // pqが空になるか、K個取ったら終わり
    while (!pq.empty() && picked < K){
      ll cand = pq.top();
      if (cand & (1LL<<d) ){
        pq.pop();
        picked++;
        picked_num.p_b(cand & (~(1LL<<d)) ); // 桁を折る
      }
      else{
        // K個取り切れなかったので、その桁は諦める

        // 取った数字を全てpqに戻す
        // pqに残っているものは桁が最初から折れており、picked_num の中にあるものは桁を折ってある
        for (ll pnum : picked_num) pq.push(pnum);
        break;
      }
    }
    // K個取れていたら、その桁を立てることができる
    // その桁が立っていない数字は使えないので、捨てる
    if (picked == K){
      bits[d] = true;

      // 次以降は、この桁が立っているものしか使えないので、今 picked_num に入っているものと、pq に残っているもののうち この桁が立っているものだけを再利用する
      while (!pq.empty()){
        ll cand = pq.top();
        if (cand & (1LL<<d)){
          pq.pop();
          picked_num.p_b(cand & (~(1LL<<d)));
        }
        else break;
      }
      // 使えるものだけpqに戻す
      pq = priority_queue<ll>();
      for (ll pnum : picked_num) pq.push(pnum);
    }


  }

  // 答えを出す
  ll ans = 0;
  REP(d, 1, biggest_d+1){
    // d : 1 ~ biggest_d
    if (bits[d-1]) ans += (1LL << (d-1));
  }

  cout << ans << endk;




}