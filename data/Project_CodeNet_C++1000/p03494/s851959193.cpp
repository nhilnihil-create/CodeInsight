#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> cnt(N);

  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    while (A % 2 == 0) {
      A /= 2;
      cnt.at(i)++;
    }
  }
  auto minmax = std::minmax_element(cnt.begin(), cnt.end());
  cout << *minmax.first << endl;
}