#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  int n = max({A, B, C});
  cout << n * ((1 << K) -1) + A + B + C << endl;
}