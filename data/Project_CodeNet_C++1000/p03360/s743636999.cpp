#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;

  cout << A + B + C + (pow(2, K) - 1) * max({A, B, C}) << endl;
  return 0;
}