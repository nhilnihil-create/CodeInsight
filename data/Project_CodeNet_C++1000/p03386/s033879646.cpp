#include <bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/abc093/tasks/abc093_b

int main() {
  int A, B, K;
  cin >> A >> B >> K;

  for (int i = A; i <= min(B, A + K - 1); i++) cout << i << endl;
  for (int i = max(B - K + 1, A + K); i <= B; i++) cout << i << endl; 
}