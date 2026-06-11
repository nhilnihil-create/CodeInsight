#include<bits/stdc++.h>
using namespace std;
int main() {
  long long n, k; cin >> n >> k;
  long long r = 0;
  if (k == 0) {
    cout << n * n << endl;
    return 0;
  }
  for (int b = k+1; b <= n; b++) {
    int cnt = b - k;
    int loop = n / b;
    r += loop * cnt;
    r += max(n % b - (k - 1), 0ll);
  }
  cout << r << endl;
}