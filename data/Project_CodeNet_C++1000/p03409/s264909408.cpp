#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A.at(i).second >> A.at(i).first;
  for (int i = 0; i < N; i++) cin >> B.at(i).first >> B.at(i).second;

  sort(A.rbegin(), A.rend());
  sort(B.begin(), B.end());

  int ans = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (B.at(i).first > A.at(j).second && B.at(i).second > A.at(j).first) {
        A.at(j).first = 2 * N;
        ans++;
        break;
      }
    }
  }

  cout << ans << "\n";
}