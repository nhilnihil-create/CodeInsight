#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, k, d = 0;
  vector<int> vec;
  cin >> a >> b >> k;

  if (a > b) {
    d = b;
  }
  else {
    d = a;
  }

  for (int i = 1; i <= d; i++) {
    if (a % i == 0 && b % i == 0) {
      vec.push_back(i);
    }
  }
  sort(vec.begin(), vec.end(), greater<>());

  cout << vec.at(k-1) << endl;
}