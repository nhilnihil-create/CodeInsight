#include <bits/stdc++.h>
using namespace std;
int main(){
  int s,a,b,c;
  cin >> s;
  a = s / 100;
  b = (s - a * 100) / 10;
  c = (s - a * 100 - b * 10) / 1;
  cout << a + b + c;
  
  return 0;
}