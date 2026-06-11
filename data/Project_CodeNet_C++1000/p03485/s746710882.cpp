#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  int r_avg; //切り上げの平均

  cin >> a >> b ;

  //単純に条件分岐してみる場合
  r_avg = ( a + b ) / 2 ;
  if ( ( r_avg * 2 ) != (a + b )){
    r_avg = r_avg + 1;
  } 
  cout << r_avg << endl;
}