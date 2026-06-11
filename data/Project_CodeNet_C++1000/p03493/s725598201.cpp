#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  int digit_100, digit_10, digit_1;
  
  // 変数aで入力を受け取る
  cin >> a;
  
  digit_100 =  a / 100 ;
  digit_10 = (a - 100* digit_100) / 10;
  digit_1 = (a - 100 * digit_100 -10 * digit_10) /1;
  
  cout << digit_100 + digit_10 + digit_1<< endl;
}