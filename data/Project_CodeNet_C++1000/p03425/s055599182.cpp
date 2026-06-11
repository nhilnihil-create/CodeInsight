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

  string s ;
  int N ;
  ll m=0 ,a=0 ,r=0 ,c=0 , h=0 ;
  ll D[5];
  int P[10]={0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,2};
  int Q[10]={1 ,1 ,1 ,2 ,2 ,3 ,2 ,2 ,3 ,3};
  int R[10]={2 ,3 ,4 ,3 ,4 ,4 ,3 ,4 ,4 ,4};

  cin >> N;
  for ( int i =0; i < N ; i ++){
    cin >> s ;
    if ( s[0]== 'M') m++;
    if ( s[0]== 'A') a++;
    if ( s[0]== 'R') r++;
    if ( s[0]== 'C') c++;
    if ( s[0]== 'H') h++;
  }
  D[0]= m , D[1]= a , D[2]= r , D[3]= c , D[4]= h ;
  ll res =0;
  for ( int d =0; d <10; d ++)
  res += D [P[ d ]]* D[Q[ d ]]* D[R[ d ]];
  cout << res << endl;

  



 
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