#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {

  string a, b;
  cin >> a >> b;
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  if(b > a)cout << "Yes";
  else cout << "No";
  return 0;
}
