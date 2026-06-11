#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,A,answer = INT_MAX;
  cin >> N;
  for (int n = 0; N; N--, n = 0) {
    for (cin >> A; !(A%2); n++, A /= 2);
    answer = min(answer,n);
  }
  cout << answer;
}