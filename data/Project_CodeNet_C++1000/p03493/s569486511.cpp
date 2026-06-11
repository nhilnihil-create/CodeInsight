#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int A,B,C,D;
  cin >> A;
  
  B = A / 100; //100のくらい
  C = A % 2; //1の位
  D = A / 10 % 10; //10の位
  
  cout << B + C + D << endl;
  
}