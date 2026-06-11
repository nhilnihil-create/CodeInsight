#include<bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  int N = (int)S.size();
  vector<int>A(N);
  for (int i = 0; i < N; i ++) {
    A[i] = (int)S[i] - (int)'0';
  }
  int ans = 10000;
  for (int i = 0; i < N - 2; i ++) {
    int kj = A[i] * 100 + A[i + 1] * 10 + A[i + 2];
    if (ans > max(753 - kj, kj - 753)) {
      ans = max(753 - kj, kj - 753);
    }
  }
  cout << ans << endl;
}
