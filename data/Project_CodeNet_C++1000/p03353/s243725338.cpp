#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int K;
  string s;
  cin >> s >> K;
  int sz = s.size();
  set<string> hash;
  for (int k = 1; k <= K; ++k) {
    for (int i = 0; i+k-1 < sz; ++i) {
      hash.insert(s.substr(i, k));
    }
  }
  for (auto &h : hash) {
    K--;
    if (K == 0) {
      cout << h << endl;
      break;
    }
  }
  return 0;
}

