#include <bits/stdc++.h>
using namespace std;

int main() {
  int s, a, b, c;
  cin >> s;
  a = s%2;
  b = (s/10)%2;
  c = (s/100)%2;

  int ans = a+b+c;
  cout << ans << endl;
}