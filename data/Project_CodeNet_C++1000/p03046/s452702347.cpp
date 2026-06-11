// g++ -O3 -fmax-errors=1 -fsanitize=undefined -fsanitize=address -sanitize=leak 
#include <bits/stdc++.h>

// length 2^{M+1} string "a"
// each number in [0, 2^M) appears exactly twice
//
// XOR の fact: 0 xor 1 xor ... xor 2^{n-1}-1 = 0000 (n even) if n >= 2
//
using namespace std;

int main() {
  int m, k;
  cin >> m >> k;
  if (m == 0) {
    // 0 0
    if (k == 0) {
      cout << "0 0" << endl;
    } else {
      cout << "-1" << endl;
    }
  } else if (m == 1) {
    // 0 => 0 0 1 1
    if (k == 0) {
      cout << "0 0 1 1" << endl;
    } else {
      cout << "-1" << endl;
    }
  } else {
    int n = (1 << m);
    if (k >= n) {
      cout << "-1" << endl;
      return 0;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) 
      if (i != k) ans.emplace_back(i);
    ans.emplace_back(k);
    for (int i = n-1; i >= 0; --i)
      if (i != k) ans.emplace_back(i);
    ans.emplace_back(k);
    for (int i = 0; i < ans.size(); ++i) {
      if (i > 0) cout << ' ';
      cout << ans[i];
    }
    cout << endl;
  }
}
