// https://atcoder.jp/contests/abc088/tasks/abc088_a
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  int mod = N % 500;
  (mod <= A) ? cout << "Yes" : cout << "No";
  return 0;
}
