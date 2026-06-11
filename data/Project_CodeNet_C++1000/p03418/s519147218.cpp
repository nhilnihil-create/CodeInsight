#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  long long res = 0;
  for (int b = k + 1; b <= n; b++) {
    int num = b - k;
    // xk x2k x3k x4k

    int rem = n % b;

    res += n / b * num;

    if (n % b >= k) 
      res += n % b - k + (k != 0);

    // int x = n / b;

    // find how many time it repeats 
  }   
  cout << res << '\n';
  return 0;
}