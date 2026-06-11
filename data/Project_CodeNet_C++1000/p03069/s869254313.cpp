#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int N;
  string S;
  cin >> N >> S;
  int white[N] = {0};
  int black[N] = {0};
  if (S[0] == '.') {
    white[0] = 1;
    black[0] = 0;
  }
  else {
    white[0] = 0;
    black[0] = 1;
  }
  for (int i = 1; i < N; i++) {
    if (S[i] == '.') {
      white[i] = white[i - 1] + 1;
      black[i] = black[i - 1];
    }
    else {
      white[i] = white[i - 1];
      black[i] = black[i - 1] + 1;
    }
  }
  int ans = 11451419;
  for (int i = 0; i < N; i++) {
    ans = min(ans,black[i] + white[N - 1] - white[i]);
  }
  ans = min(ans,white[N - 1]);
  cout << ans << endl;
  return 0;
}
