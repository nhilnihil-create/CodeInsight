#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define ll long long
static const int MAX = 10000;
static const ll INFTY = 1e12;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll conv3(ll x){
  return x * (x-1) * (x-2) / (6);
}

ll conv2(ll x){
  return x * (x-1) / (2);
}

int main() {

  int c[3][3] = {0};
  REP(i, 3)REP(j, 3)cin >> c[i][j];

  if(c[0][1]-c[0][0] == c[1][1]-c[1][0] && c[1][1]-c[1][0] == c[2][1]-c[2][0]){
    if(c[0][2]-c[0][1] == c[1][2]-c[1][1] && c[1][2]-c[1][1] == c[2][2]-c[2][1]){
      cout << "Yes" << endl;
      return 0;
    } 
  }
  cout << "No" << endl;
  return 0;

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