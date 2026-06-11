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

  int H, W, N;
  cin >> H >> W >> N;

  int sy, sx;
  cin >> sy >> sx;
  --sy;
  --sx; //0-indexed

  string S, T;
  cin >> S >> T;


  //i = N ～ 1 につき、「i回目の動作前にどのマスにいれば、青木くんは負けないか」という範囲をとっていく。
  //--> 「1回目の動作前」＝初期状態なので、そこにsx, syが含まれればYESとなる
  //途中の段階で範囲がなくなれば、その時点でNOを出力してreturn 0;

  //左右の場合
  int min_limit = 0; //左側限界
  int max_limit = W-1; //右側限界 閉区間なので注意
  char sdir;
  char tdir;
  
  //最後の高橋君の動きを確認し、N回目（最後）の動作前の限界をとる
  sdir = S.at(N-1);
  if (sdir == 'L'){ //左側限界にいると落ちる
    min_limit += 1;
//    cout << min_limit << endl;
  }
  else if (sdir == 'R'){ //右側限界にいると落ちる
    max_limit -= 1;
  }
  //区間がなくなったら"NO"して終了
  if (min_limit > max_limit){
    cout << "NO" << endl;
    return 0;
  }

  //i = N-1 ～ 1 
  for (int i = N-1; i > 0; i--){
    char sdir = S.at(i-1);
    char tdir = T.at(i-1);

    //まずは青木くんの動作を確認
    if (tdir == 'L'){ //座標が下がる方に動けるので、max限界が広がる
      max_limit = min(W-1, max_limit + 1); //ただし盤面を超えない
    }
    else if (tdir == 'R'){ //座標が上がる方に動けるので、min限界が広がる
      min_limit = max(0, min_limit - 1); //盤面を超えない
    }

    //次は高橋くんの動作
    if (sdir == 'L'){ //座標が下がる方に動かされるので、min限界が狭まる
      min_limit += 1; //これは盤面を超えてもいい（超えるような時はどうせmaxとminが入れ替わる＝範囲が切れるので）
    }
    else if (sdir == 'R'){ //座標が上がる方に動かされるので、max限界が狭まる
      max_limit -= 1;
    }

    //範囲が切れていたらNO
    if (min_limit > max_limit){
    cout << "NO" << endl;
    return 0;
    }
  }
  //ループを抜けた＝範囲は切れていない

  //初期位置は生存圏内か？
  if (!((sx >= min_limit) && (sx <= max_limit))){
//    cout << sx << ' ' << min_limit << ' ' << max_limit << endl;
    cout << "NO" << endl;
    return 0;
  }


  //上下の場合
  min_limit = 0;
  max_limit = H-1;
  
  //最後の高橋君の動きを確認し、N回目（最後）の動作前の限界をとる
  sdir = S.at(N-1);
  if (sdir == 'U'){
    min_limit += 1;
//    cout << min_limit << endl;
  }
  else if (sdir == 'D'){ //右側限界にいると落ちる
    max_limit -= 1;
  }
  //区間がなくなったら"NO"して終了
  if (min_limit > max_limit){
    cout << "NO" << endl;
    return 0;
  }

  //i = N-1 ～ 1 
  for (int i = N-1; i > 0; i--){
    char sdir = S.at(i-1);
    char tdir = T.at(i-1);

    //まずは青木くんの動作を確認
    if (tdir == 'U'){ //座標が下がる方に動けるので、max限界が広がる
      max_limit = min(H-1, max_limit + 1); //ただし盤面を超えない
    }
    else if (tdir == 'D'){ //座標が上がる方に動けるので、min限界が広がる
      min_limit = max(0, min_limit - 1); //盤面を超えない
    }

    //次は高橋くんの動作
    if (sdir == 'U'){ //座標が下がる方に動かされるので、min限界が狭まる
      min_limit += 1; //これは盤面を超えてもいい（超えるような時はどうせmaxとminが入れ替わる＝範囲が切れるので）
    }
    else if (sdir == 'D'){ //座標が上がる方に動かされるので、max限界が狭まる
      max_limit -= 1;
    }

    //範囲が切れていたらNO
    if (min_limit > max_limit){
    cout << "NO" << endl;
    return 0;
    }
  }
  //ループを抜けた＝範囲は切れていない

  //初期位置は生存圏内か？
  if (!((sy >= min_limit) && (sy <= max_limit))){
//    cout << sx << ' ' << min_limit << ' ' << max_limit << endl;
    cout << "NO" << endl;
    return 0;
  }

  //生き残った
  cout << "YES" << endl;

// -- main() end -- //
}


 