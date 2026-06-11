#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, cnt = 0, ans = 0;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i%j == 0 && i%2 == 1) cnt++;
    }
    if (cnt == 8) ans++;
    cnt = 0;
  }
  
  cout << ans << endl;
}