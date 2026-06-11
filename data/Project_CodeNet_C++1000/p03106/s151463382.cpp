#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  vector<int> vec;

  if (min(a, b) == 1) {
    cout << 1 << endl;
    return 0;
  }

  for (int i = 1; i <= max(a, b); i++) {
    if (a % i == 0 && b % i == 0) {
      vec.push_back(i);
    }
  }

  cout << vec[vec.size() - k] << endl;
}
