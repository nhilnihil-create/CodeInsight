#include <bits/stdc++.h>
using namespace std;
 
int main() {
  float a;
  float b;
  float ave;
  int i_ave;
  int sum;
  // 変数aで入力を受け取る
  cin >> a >> b;
  ave = (a+b)/2.0;
  i_ave = ave; 
  sum = a + b;
  cout << i_ave+(sum % 2) * (sum % 2) << endl;
}