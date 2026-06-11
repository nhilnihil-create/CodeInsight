#include <bits/stdc++.h>
#include <vector>
using namespace std;

inline bool solve (int n) {
  int count = 0;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) count += 1;
  }

  if (count == 8 && n % 2 ==1) {
    return true;
  } else {
    return false;
  }
}


int main() {
  int cnt = 0;
  int N; cin >> N;

  for (int i = 1; i <= N; ++i) {
    if (solve(i) == true) {
      cnt += 1;
    } else {
        continue;
    }
  }

  cout << cnt << endl;

  return 0;
}