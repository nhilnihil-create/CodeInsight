#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  int cnt = 0;
  vector<int> v;
  for (int i = 1; i <= min(a, b); i++) {
    if (a % i == 0 && b % i == 0) {
      cnt++;
      v.push_back(i);
    }
  }
  cout << v.at(v.size() - k) << endl;
  return 0;
}