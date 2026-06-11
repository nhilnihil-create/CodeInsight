#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  int sum_length = 0;
  for (int i = 0; i < N; ++i) {
    cin >> L.at(i);
    sum_length += L.at(i);
  }

  int max_length = *max_element(L.begin(), L.end());
  sum_length -= max_length;

  cout << (max_length < sum_length ? "Yes" : "No") << endl;
  return 0;
}
