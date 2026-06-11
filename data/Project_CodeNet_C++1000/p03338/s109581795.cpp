#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 0;
  for (int i=1; i<N; i++) {
    int cnt = 0;
    for (char c='a'; c<='z'; c++) {
      bool left = false; bool right = false;
      for (int j=0; j<i; j++) {
        if (S[j] == c) {
          left = true;
        }
      }
      for (int j=i; j<N; j++) {
        if (S[j] == c) {
          right = true;
        }
      }
      if (left&&right) {
        cnt++;
      }
    }
    if (cnt > ans) {
      ans = cnt;
    }
  }
  cout << ans << '\n';
  return 0;
}