#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N, K;
  cin >> N >> K;
  if (K % 2 == 1) {
    cout << (N / K) * (N / K) * (N / K) << endl;
  }
  else {
    long long int X = N / K;
    long long int Y = N / (K / 2) - N / K;
    cout << X * X * X + Y * Y * Y << endl;
  }
}