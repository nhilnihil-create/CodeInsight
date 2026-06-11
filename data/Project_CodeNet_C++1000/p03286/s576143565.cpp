#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  vector<int> v;
  cin >> N;
  if (N == 0) {
    cout << '0';
    return 0;
  }
  for (int i = 0; N != 0; i++, N -= N & 1, N /= -2) {
    v.push_back(N & 1);
  }
  reverse(v.begin(), v.end());
  for (auto i : v) {
    cout << i;
  }
  return 0;
}