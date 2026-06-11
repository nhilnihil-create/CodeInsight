#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X, donuts[100], sum = 0, min_donut = 1000;
  cin >> N >> X;

  for (int i = 0; i < N; i++) {
    cin >> donuts[i];
    sum += donuts[i];
    if (donuts[i] < min_donut) min_donut = donuts[i];
  }

  cout << (N + (X - sum) / min_donut) << endl;
}