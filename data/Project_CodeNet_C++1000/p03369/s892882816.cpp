#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string s;
  cin >> s;

  int topping = 0;
  if (s.at(0) == 'o') topping += 100;
  if (s.at(1) == 'o') topping += 100;
  if (s.at(2) == 'o') topping += 100;

  int ans = 700 + topping;
  cout << ans << endl;
  return 0;
}