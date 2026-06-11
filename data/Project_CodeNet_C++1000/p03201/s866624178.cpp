#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<bool> used(N);
  multiset<int> B;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    B.insert(A[i]);
  }
  int ans = 0;
  while (!B.empty()) {
    int M = *B.rbegin();
    B.erase(B.find(M));

    auto it = B.find((1 << ((int)log2(M)) + 1) - M);
    if (it != B.end()) {
      ans++;
      B.erase(it);
    }
  }
  cout << ans << endl;
}