#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  int calc = 0;
  int tmp = N;
  while (tmp > 0) {
    calc += tmp % 10;
    tmp /= 10;
  }
  if (N % calc == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}