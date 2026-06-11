#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long n, m;
  string s, t;
  cin >> n >> m;
  cin >> s >> t;

  long long result = 0;
  long long lcd = n * m / __gcd(n, m);
  long long steplcd = (lcd / n) * (lcd / m);

  for (long long i = 0; i < lcd; i += steplcd) {
    if (s[i * n / lcd] != t[i * m / lcd]) {
      result = -1;
      break;
    }
  }
  if (result != -1) result = lcd;

  cout << result << endl;
  return 0;
}