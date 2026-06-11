#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<tuple<string, int, int>> X(N);
  for (int i = 0; i < N; i++) {
    cin >> get<0>(X.at(i)) >> get<1>(X.at(i));
    get<1>(X.at(i)) = 100 - get<1>(X.at(i));
    get<2>(X.at(i)) = i + 1;
  }
  sort(X.begin(), X.end());
  for (int i = 0; i < N; i++) {
    cout << get<2>(X.at(i)) << endl;
  }
}