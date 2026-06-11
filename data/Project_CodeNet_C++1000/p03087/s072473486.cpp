#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q, l, r;
  cin >> N >> Q;

  string S;
  cin >> S;

  vector<int> s(N+1, 0);
  for (int i = 0; i < N; ++i) {
    if (i + 1 < N && S.at(i) == 'A' && S.at(i + 1) == 'C')
      s.at(i + 1) = s.at(i) + 1;
    else
      s.at(i + 1) = s.at(i);
  }

  for (int i = 0; i < Q; i++) {
    cin >> l >> r;
    l--;
    r--;
    cout << s.at(r) - s.at(l) << endl;
  }
}