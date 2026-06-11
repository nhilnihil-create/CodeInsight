#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  int num = 0;
  for (int i = 0; i < M; ++i) {
    int A;
    cin >> A;
    if (A < X) ++num;
  }
  cout << min(num, M - num) << endl;
}