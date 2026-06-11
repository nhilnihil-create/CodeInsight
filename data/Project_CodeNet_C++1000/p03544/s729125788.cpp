#include <bits/stdc++.h>
using namespace std;

int64_t lucas(int n) {
  vector<int64_t> a;
  // n => 0
  a.push_back(2);
  // n => 1
  a.push_back(1);
  
  if (n > 1) {
    for (int i = 2; i <= n; i++) {
      int64_t x = a.at(i - 2) + a.at(i - 1);
      a.push_back(x);
    }
  }
  
  return a.at(n);
}

int main() {
  int N;
  cin >> N;

  cout << lucas(N) << endl;
}