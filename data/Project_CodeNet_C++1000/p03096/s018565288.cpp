#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld  = long double;
using pll = pair<ll, ll> ;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=1LL<<60;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld EPS = 1e-9; //微調整用（EPSより小さいと0と判定など）
 
#define gcd __gcd //llは受け取ってくれない
int lcm(int a, int b){return a / gcd(a, b) * b;}
#define ALL(a) a.begin(),a.end() //sort(ALL(vec));
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define PB push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに

//最大値、最小値を更新する。aよりbのが大きい（小さい）か等しければaを更新してtrueを返す。そうでなければ何もせずfalseを返す chmax(nowmax,x);
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}
// ----- template end ---- //
 
// ------- library ------- //



// ----- library end ----- //



int main() {

  int N;
  cin >> N;

  if (N<=2){
    cout << 1 << endl;
    return 0;
  }

  
  vector<ll> DP(N+1, 1); //DP[0]を入れる必要があるので0-indexed

  //color(0-indexed)が直前に登場した時の位置
  //(色番号(.at())は0-indexedで、格納する位置は1-indexed)
  vector<int> prev(200000, -1);

  int nowcolor;
  REP(i, 1, N+1){
    // iは1-indexed !!
    cin >> nowcolor;
    nowcolor -= 1;
    if (prev.at(nowcolor)==-1){
      //未登場なら前のDPを引き継ぐだけ
      DP.at(i) = DP.at(i-1);
    }
    else if (prev.at(nowcolor)==i-1){
      //直前に出たばかりなら、やはり前のDPを引き継ぐだけ
      DP.at(i) = DP.at(i-1);
    }
    else{
      //1つ以上前に出ていた場合、その時のDPも引き継ぐ
      DP.at(i) = (DP.at(i-1) + DP.at(prev.at(nowcolor))) % MOD;
    }
    prev.at(nowcolor) = i;
  }

  cout << DP.at(N) << endl;


// -- main() end -- //
}
