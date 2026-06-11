#include <bits/stdc++.h>
using namespace std;

bool isAGCT(char c) {
  return (c == 'A' || c == 'G' || c == 'C' || c == 'T');
}

int main() {
  string S;
  cin >> S;
  S = 'X' + S;
  int N = S.size();
  int res = 0;
  for (int i = 0; i < N;) {
    if (!isAGCT(S[i])) {
      int j = i+1;
      while (j < N && isAGCT(S[j])) ++j;
      res = max(res, j - i - 1);
      i = j;
    }
  }
  cout << res << endl;
}