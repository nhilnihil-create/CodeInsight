#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define ll long long
static const ll MAX = 10000;
static const ll INFTY = 1e12;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
using P = pair<ll, ll>;
// 入力
// 入力
ll h, w;
ll startX, startY, endX, endY;
vector<vector<char>> s;
vector<vector<ll>> cnts; // 魔法使った回数


int main() {

  ll N; cin >> N;
  vector<vector<ll>> A(2, vector<ll>(N, 0));
  // ll A[2][N] = {0};
  ll sum = 0;

  REP(i, 2){
    REP(j, N){
      cin >> A[i][j];
      sum += A[i][j];
    }
  }

  ll sum1[N] = {0};
  sum1[0] = 0;
  REP1(i, N){
    sum1[i] = A[1][i-1]+sum1[i-1];
  }

  ll sum2[N] = {0};
  sum2[N-1] = 0;
  REP1(i, N){
    sum2[N-1-i] = A[0][N-i]+sum2[N-i];
  }
  ll min_ = MAX;
  REP(i, N){
    min_ = min(min_, sum1[i]+sum2[i]);
  }
  // REP(i, N){
  //   cout << sum1[i] << " ";
  // }cout << endl;
  // REP(i, N){
  //   cout << sum2[i] << " ";
  // }cout << endl;
  cout << sum-min_ << endl;


   
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         pass System Test!
*/