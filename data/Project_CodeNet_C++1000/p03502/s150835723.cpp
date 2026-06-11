#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int ketanowa (int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int N;
  cin >> N;
  if ((N % ketanowa(N)) == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
return 0;
}