#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<long long> A(N);
  long long totA = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    totA += A.at(i);
  }

  vector<long long> B(N);
  long long totB = 0;
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
    totB += B.at(i);
  }

  if (totA < totB) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> C(N);
  long long ans = 0;
  long long cost = 0;
  for (int i = 0; i < N; i++) {
    C.at(i) = A.at(i) - B.at(i);
    if (C.at(i) < 0) {
      ans++;
      cost += C.at(i) * (-1);
    }
  }

  sort(C.begin(), C.end());
  reverse(C.begin(), C.end());

  int i = 0;
  while (cost > 0) {
  cost -= C.at(i);
  i++;
  ans++;
  }

  cout << ans << endl;
}