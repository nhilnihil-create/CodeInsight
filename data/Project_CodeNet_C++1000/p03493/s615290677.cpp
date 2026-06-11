#include <bits/stdc++.h>
using namespace std;

int main() {
  int a1,a2,b1,b2,c2;
  cin >> a1;
  b1 = a1%100;//11,10,01,00
  a2 = (a1-b1)/100;
  c2 = b1%10;//1,0
  b2 = (b1-c2)/10;
  
  cout << a2+b2+c2 << endl;
}