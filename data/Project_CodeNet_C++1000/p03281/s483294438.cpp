#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  int ans = 0;  

  rep2(i, n) {
    if (i % 2 == 1) {
      int count = 0;
      rep2(j, i) if (i % j == 0) count++;
      if (count == 8) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
