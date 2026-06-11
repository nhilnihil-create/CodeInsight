#include <bits/stdc++.h>
using namespace std;

bool palindromes(int n) {
  int m = 0;
  int t = n;
  int r = 0;
  while(t != 0) {
    r = t%10;
    m = m*10 + r;
    t /= 10;
  }
  if (n == m) return true;
  else return false;
}

int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; i++) {
    ans += palindromes(i);
  }
  cout << ans << endl;
}