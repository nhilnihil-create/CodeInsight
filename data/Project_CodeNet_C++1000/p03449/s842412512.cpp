#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a1(n);
  rep(i, n) cin >> a1.at(i);
  vector<int> a2(n);
  rep(i, n) cin >> a2.at(i);

  vector<int> sum_a1(n + 1);
  for (int i = 1; i <= n; i++) {
    sum_a1.at(i) = sum_a1.at(i - 1) + a1.at(i - 1);
  }
  vector<int> sum_a2(n + 1);
  for (int i = 1; i <= n; i++) {
    sum_a2.at(i) = sum_a2.at(i - 1) + a2.at(i - 1);
  }

  int max_candies = 0;
  for (int i = 1; i <= n; i++) {
    int candies = sum_a1.at(i);
    candies += sum_a2.at(n) - sum_a2.at(i - 1);
    max_candies = max(max_candies, candies);
  }

  cout << max_candies << endl;
  return 0;
}