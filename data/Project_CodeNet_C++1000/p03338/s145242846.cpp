#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int res = 0;
  for (int i = 0; i <= N; ++i) {
    int con = 0;
    for (int j = 0; j < 26; ++j) {
      char c = 'a' + j;
      bool zen = false, kou = false;
      for (int k = 0; k < i; ++k) if (S[k] == c) zen = true;
      for (int k = i; k < N; ++k) if (S[k] == c) kou = true;
      if (zen && kou) ++con;
    }
    res = max(res, con);
  }
  cout << res << endl;
}
  