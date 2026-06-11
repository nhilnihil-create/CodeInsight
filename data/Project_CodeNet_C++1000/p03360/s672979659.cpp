#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(3);
  cin >> a.at(0) >> a.at(1) >> a.at(2);
  int K;
  cin >> K;
  sort(a.begin(), a.end(), [](int l, int r) { return l > r; });
  for (int i = 0; i < K; i++) {
    a.at(0) *= 2;
  }
  int ans = a.at(0) + a.at(1) + a.at(2);
  cout << ans << endl;
}