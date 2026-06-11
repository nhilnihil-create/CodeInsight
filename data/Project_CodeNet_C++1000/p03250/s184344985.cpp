#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> n(3);
  cin >> n[0] >> n[1] >> n[2];
  sort(n.begin(), n.end(), greater<int>());
  cout << n[0] * 10 + n[1] + n[2];
}