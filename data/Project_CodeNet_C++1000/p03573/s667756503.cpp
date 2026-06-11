#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c;
  cin >> a >> b >> c;
  int ans;
  if (a == b) {
    ans = c;
  } else if (a == c) {
    ans = b;
  } else if (b == c) {
    ans = a;
  }
  
  cout << ans << '\n';
  return 0;
}