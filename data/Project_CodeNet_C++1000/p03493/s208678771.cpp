#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, s;
  cin >> a;
  s = a % 10;
  a = a / 10;
  s = s + a%10;
  a = a / 10;
  s = s + a%10;
  cout << s << endl;
}