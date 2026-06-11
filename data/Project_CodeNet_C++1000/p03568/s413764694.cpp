#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int Pow(int a, int n) {
  if (n == 0) return 1;
  if (n == 1) return a;
  if (n % 2 == 1) return (a * Pow(a, n-1));
  int t = Pow(a, n/2);
  return t*t;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int cnt_odd = 0, cnt_even = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] % 2 == 0) cnt_even++;
    else cnt_odd++;
  }
  int ans = Pow(3, N) - Pow(2, cnt_even);
  cout << ans << endl;
}
