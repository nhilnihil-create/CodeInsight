#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> p(N);
  int sum_value = 0;
  for (int i = 0; i < N; ++i) {
    cin >> p.at(i);
    sum_value += p.at(i);
  }

  int half_value = *max_element(p.begin(), p.end());

  cout << sum_value - half_value + (half_value / 2) << endl;
  return 0;
}
