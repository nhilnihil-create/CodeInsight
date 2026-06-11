#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, ans=0;
  cin >> a;
  
  if (a <= 999) ans = 999;
  if (a <= 888) ans = 888;
  if (a <= 777) ans = 777;
  if (a <= 666) ans = 666;
  if (a <= 555) ans = 555;
  if (a <= 444) ans = 444;
  if (a <= 333) ans = 333;
  if (a <= 222) ans = 222;
  if (a <= 111) ans = 111;
  
  cout << ans << endl;
}