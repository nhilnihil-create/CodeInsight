#include <bits/stdc++.h>

using namespace std;

long long n, d, k;

int sum(long long x) {
  int s = 0;
  while (x) {
    s += x % 10;
    x /= 10;
  }
  return s;
}
int main() {
	cin >> k;
	cout << 1 << "\n";
	n = 1; d = 1;
	k--;
	while(k) {
		if(sum(n + 10 * d) * (n + d) > sum(n + d) * (n + 10 * d))
      d *= 10;
		n += d;
    cout << n << "\n";
    k--;
	}
}
