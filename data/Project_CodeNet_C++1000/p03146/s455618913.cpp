#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int res = 1;
  set<int> se;
  se.insert(N);
  while (true) {
    if (N % 2 == 0) N /= 2;
    else N = N*3 + 1;
    ++res;
    if (se.count(N)) break;
    se.insert(N);
  }
  cout << res << endl;
}