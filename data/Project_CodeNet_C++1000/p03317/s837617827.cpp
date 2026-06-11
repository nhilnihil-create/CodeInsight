#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  N--, K--;
  cout << (N + K - 1) / K << "\n";
}