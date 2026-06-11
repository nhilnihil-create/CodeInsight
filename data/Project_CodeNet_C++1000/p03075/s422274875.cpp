#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >> e >> k;

  vector<int> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  v.push_back(d);
  v.push_back(e);

  sort(v.begin(), v.end());

  if(v[4] - v[0] > k) cout << ":(\n";
  else cout << "Yay!\n";

  return 0;
}