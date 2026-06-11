#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool ok = false;
  for (int x = 0; x <= N; ++x) {
    for (int y = 0; y <= N; ++y) {
      if (x* 4 + y * 7 == N) ok = true;
    }
  }
  if (ok) puts("Yes");
  else puts("No");
}
      