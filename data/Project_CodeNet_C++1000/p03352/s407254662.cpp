#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;

int main() {
  int X;
  cin >> X;
  int ans = 1;
  if(X == 1) { cout << 1; return 0; }
  for(int i = 2; i < 40; i++) {
    int a = i * i;
    for(int j = a; j <= X; j *= i) {
      if(ans < j) ans = j;
    }
  }

  cout << ans;
  return 0;
}