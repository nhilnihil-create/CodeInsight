#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N;
  cin >> N;
  vector<long long int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < N; i++) cin >> B.at(i);
  long long int SA = 0, SB = 0;
  for (int i = 0; i < N; i++) {
    SA += A.at(i);
    SB += B.at(i);
  }
  long long int K = SB - SA;
  long long int k1 = 0, k2 = 0;
  for (int i = 0; i < N; i++) {
    if (A.at(i) == B.at(i)) continue;
    else if (A.at(i) > B.at(i)) k1 += A.at(i) - B.at(i);
    else k2 += (B.at(i) - A.at(i) + 1) / 2;
  }
  if (max(k1, k2) <= K) cout << "Yes" << endl;
  else cout << "No" << endl;
}