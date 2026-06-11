#include <bits/stdc++.h>
using namespace std;

int main() {
  long long res = 0;
  long long ma = 0;
  for (int i = 0; i < 5; ++i) {
    long long A;
    cin >> A;
    long long rem = A % 10;
	if (rem == 0) res += A;
    else {
      res += A + (10 - rem);
      ma = max(ma, 10 - rem);
    }
  }
  cout << res - ma << endl;
}
