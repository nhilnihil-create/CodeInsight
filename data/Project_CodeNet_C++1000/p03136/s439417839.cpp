#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
using int64 = long long;

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }
  int max_of_L = *max_element(L.begin(), L.end());
  int sum_of_L = accumulate(L.begin(), L.end(), 0);
  if (sum_of_L > 2 * max_of_L) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}