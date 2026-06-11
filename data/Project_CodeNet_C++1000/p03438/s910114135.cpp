#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector A(N, 0), B(N, 0);
  for (auto &a : A) cin >> a;
  for (auto &a : B) cin >> a;
  long X = 0, Y = 0;
  for (int i = 0; i < N; i++) {
    if (A.at(i) < B.at(i)) X += (B.at(i) - A.at(i)) / 2;
    else Y += A.at(i) - B.at(i);
  }
  cout << ((Y > X) ? "No" : "Yes") << "\n";
}