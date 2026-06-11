#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i].first;
    X[i].second = i;
  }
  sort(X.begin(), X.end());
  set<int> mid_left;
  for (int i = 0; i < N/2; i++) mid_left.insert(X[i].second);
  for (int i = 0; i < N; i++) {
    if (mid_left.count(i)) cout << X[N/2].first << endl;
    else cout << X[N/2-1].first << endl;
  }
}
