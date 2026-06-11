#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define ll long long
static const int MAX = 10000;
static const ll INFTY = 1e12;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll MRINF = 5000000000000000;

int main() {

  ll N; cin >> N;
  vector<ll> A(N), diff(N+1);
  REP(i, N){
    cin >>A[i];
  }
  ll sum = 0;
  diff[0] = A[0];
  sum += abs(diff[0]);
  REP1(i, N){
    diff[i] = A[i] - A[i-1];
    sum += abs(diff[i]);
  }
  diff[N] = 0-A[N-1];
  sum += abs(diff[N]);

  // cout << sum << endl;

  REP(i, N){
    ll  ans = sum - abs(diff[i]) - abs(diff[i+1]) + abs(diff[i]+diff[i+1]);
    cout << ans << endl;
  }

  

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