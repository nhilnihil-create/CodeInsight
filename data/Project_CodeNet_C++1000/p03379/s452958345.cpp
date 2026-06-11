#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<pair<int, int>> X(N);
  for (int i = 0; i < N; i++) {
    int given;
    cin >> given;
    X[i] = {given, i};
  }

  sort(X.begin(), X.end());

  vector<int> ans(N);
  int boundary = N/2;

  for (int idx = 0; idx < N; idx++) {
    if (idx < boundary) {
      ans[X[idx].second] = X[boundary].first;
    } else {
      ans[X[idx].second] = X[boundary-1].first;
    }
  }

  for (int x : ans) cout << x << endl;
  return 0;
}