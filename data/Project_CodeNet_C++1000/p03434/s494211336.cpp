#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  vector<int> a(N);
  for (size_t i = 0; i < N; i++) {
    cin >> a.at(i);
  }

  sort(a.begin(), a.end());

  int sum = 0;
  int p = 1;

  for (size_t i = 0; i < N; i++) {
    sum += p * a.at(i);
    p *= -1;
  }
  sum = (sum > 0) ? sum : sum * -1;
  cout << sum;
}