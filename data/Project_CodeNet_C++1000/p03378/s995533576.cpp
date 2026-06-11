#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X, A, cnt = 0;
  cin >> N >> M >> X;
  while (cin >> A) if (A < X) cnt++;
  cout << min(cnt, M - cnt) << "\n";
}
