#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//AピザX枚、BピザY枚いる
//ハーフが得な場合、min(X,Y)枚ハーフを買う
//ハーフが得な場合とは、
/*A,Bピザをmin(X,Y)枚ずつ買う時、min(X,Y)*(A + B) > 2min(X,Y) * C であれば、
ハーフで2min(X,Y) 枚買う
そうでなければ、A,Bピザをmin(X,Y)枚ずつ買う
*/
/*残りmax(X,Y)-min(X,Y)枚について、Aを買うとすると、A > C/2 のとき
ハーフを2*(max(X,Y)-min(X,Y))枚買う
そうでない時、Aをmax(X,Y)-min(X,Y)枚買う
*/

/*残りmax(X,Y)-min(X,Y)枚について、単体で買う場合とハーフで買う場合の安い方
を採用
*/

int main() {
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = 0;
  if(min(X,Y)*(A+B) > 2*min(X,Y)*C){
    ans += 2*min(X,Y)*C;
  }
  else{
    ans += min(X,Y)*(A+B);
  }

  int da = 0;//残りのAの枚数
  int db = 0;//残りのBの枚数
  if(X >= Y){
    da = X - Y;
    ans += min(A*da,2*da*C);
  }
  if( X < Y){
    db = Y - X;
    ans += min(B*db,2*db*C);
  }
  cout << ans << endl;
}