#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, D, X;
  cin >> N >> D >> X;
  vector<int> A(N);
  int ans = X + N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    ans += (D-1)/A[i];
  }
  cout << ans << endl;
}
