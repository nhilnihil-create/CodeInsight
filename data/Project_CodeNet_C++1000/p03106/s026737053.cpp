#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  vector<int> c;
  for (int i = 1; i <= min(A, B); ++i) {
    if (A % i == 0 && B % i == 0) c.push_back(i);
  }
  reverse(c.begin(), c.end());
  cout << c[K-1] << endl;
}