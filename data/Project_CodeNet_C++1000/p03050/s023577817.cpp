#include<bits/stdc++.h>
using namespace std;

int main() {
  long N; cin >> N;
  long res = 0;
  for (long k = 1; k * k <= N; k++) {
    long m = N - k;
    if (m % k) continue;
    m /= k;
    if (k < m) res += m;
  }
  cout << res << endl;
}