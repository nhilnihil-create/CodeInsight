#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> N(4); cin >> N[0] >> N[1] >> N[2] >> N[3];
  sort(N.begin(), N.end());
  cout << ((N[0] == 1 && N[1] == 4 && N[2] == 7 && N[3] == 9) ? "YES" : "NO") << endl;
}