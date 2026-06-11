#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; string S; cin >> N >> K >> S;

  vector<int> v;
  if(S.at(0) == '1') v.push_back(0);

  char c = S.at(0);
  for (int i = 0; i < N; i++) {
    int cnt = 1;
    while(i + 1 < N) {
      if(S.at(i + 1) == c) {
        i++; cnt++;
      }
      else break;
    }
    v.push_back(cnt);
    if (c == '0') c = '1';
    else c = '0';
  }

  int l = v.size();
  vector<int> b(l + 1, 0);
  for (int i = 0; i < l; i++) b.at(i + 1) = b.at(i) + v.at(i);

  int ans = 0;
  for (int i = 0; i < l; i += 2) {
    if (i == 0) {
      int r = min(l, 2 * K);
      ans = b.at(r);
    } else {
      int r = min(l, i + 2 * K);
      ans = max(ans, b.at(r) - b.at(i - 1));
    }
  }
  cout << ans << endl;
}
