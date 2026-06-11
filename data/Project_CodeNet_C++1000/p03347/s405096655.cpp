#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  if (A[0] != 0) {
    cout << -1 << endl;
    return 0;
  }
  ll num = 0;
  for (int i = 1; i < N; i++) {
    if (A[i] == A[i-1] + 1) {
      num += 1;
    } else if (A[i] <= A[i-1] + 1) {
      num += A[i];
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << num << endl;
  return 0;
}