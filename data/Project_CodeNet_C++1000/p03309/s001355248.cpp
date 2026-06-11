#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    B.at(i) = A.at(i) - i - 1;
  }
  sort(B.begin(), B.end());
  int k = B.at(N / 2);
  long long int ans = 0;
  for (int i = 0; i < N; i++) ans += abs(B.at(i) - k);
  cout << ans << endl;
}