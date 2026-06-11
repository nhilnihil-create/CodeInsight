#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;

  cin >> N;

  int fx = 0;
  for (int n = N; n > 0; n = n / 10) {
    fx += n - (n / 10 * 10);
  }

  if (N % fx == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
