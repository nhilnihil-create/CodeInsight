#include <bits/stdc++.h>
using namespace std;

int main() {
  int N1, N2, N3, N4;
  cin >> N1 >> N2 >> N3 >> N4;

  vector<int> N = {N1, N2, N3, N4};

  int ans = 0;
  for (int i = 0; i < 4; i++) {
    if (N.at(i) == 1)
      N.at(i) *= 1000;
    else if (N.at(i) == 9)
      N.at(i) *= 100;
    else if (N.at(i) == 7)
      N.at(i) *= 10;
    ans += N.at(i);
  }

  if (ans == 1974)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}