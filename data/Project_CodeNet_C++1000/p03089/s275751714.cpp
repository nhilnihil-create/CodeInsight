#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<int> ans;
  while (A.size()) {
    bool b = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
      if (A.at(i) == i + 1) {
        ans.push_back(A.at(i));
        A.erase(A.begin() + i);
        b = 1;
        break;
      }
    }
    if (!b) return cout << -1 << "\n", 0;
  }
  reverse(ans.begin(), ans.end());
  for (auto a : ans) cout << a << "\n";
}