#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  int to_0 = 0, to_N = 0;
  for (int i = 0; i < M; i++) {
    int tmp;
    cin >> tmp;
    if (tmp < X) to_0++;
    else to_N++;
  }
  cout << min(to_0, to_N) << endl;
}
