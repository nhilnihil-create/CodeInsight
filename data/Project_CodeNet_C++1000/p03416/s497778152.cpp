#include <bits/stdc++.h>
using namespace std;

bool isok(long long n) {
  vector<int> v;
  while (n) {
    v.push_back(n % 10);
    n /= 10;
  }
  auto v2 = v;
  reverse(v2.begin(), v2.end());
  return v == v2;
}

int main() {
  int A, B;
  cin >> A >> B;
  int res = 0;
  for (int n = A; n <= B; ++n) if (isok(n)) ++res;
  cout << res << endl;
}