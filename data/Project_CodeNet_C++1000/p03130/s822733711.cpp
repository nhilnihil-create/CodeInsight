#include <bits/stdc++.h>
using namespace std;

int main() {
  int a1, b1, a2, b2, a3, b3;
  cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

  int town[4] = {};
  town[a1 - 1]++, town[b1 - 1]++, town[a2 - 1]++, town[b2 - 1]++, town[a3 - 1]++, town[b3 - 1]++;

  int one = 0, two = 0;
  if (town[0] == 1) one++; if (town[0] == 2) two++;
  if (town[1] == 1) one++; if (town[1] == 2) two++;
  if (town[2] == 1) one++; if (town[2] == 2) two++;
  if (town[3] == 1) one++; if (town[3] == 2) two++;

  if (one == 2 && two == 2) cout << "YES" << endl; else cout << "NO" << endl;
}