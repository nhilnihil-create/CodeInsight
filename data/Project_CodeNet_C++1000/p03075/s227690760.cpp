#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  vector<int> p(5);
  int k;
  cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> k;
  sort(p.begin(), p.end());
  if (p[4] - p[0] > k) cout << ":(" << endl;
  else cout << "Yay!" << endl;
}
