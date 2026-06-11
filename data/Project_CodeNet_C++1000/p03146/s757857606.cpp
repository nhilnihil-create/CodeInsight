#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> SE;
  SE.insert(N);
  int cnt = 1;
  while (++cnt) {
    if (N % 2) {
      N = 3 * N + 1;
    } else {
      N = N / 2;
    }
    if (SE.count(N)) return cout << cnt << "\n", 0;
    else SE.insert(N);
  }
}