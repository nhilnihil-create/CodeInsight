#include <bits/stdc++.h>
using namespace std;

int main() {
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  int d1 = abs(a1-a2), d2 = abs(a2-a3), d3 = abs(a3-a1);
  vector<int> d = {d1, d2, d3};
  sort(d.begin(), d.end());
  cout << d[0] + d[1] << endl;
}
