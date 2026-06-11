#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, s;
  cin >> s;
  c = s % 10;
  a = s  / 100;
  b = (s - 100 * a) / 10;
  cout << a + b + c << endl;
}