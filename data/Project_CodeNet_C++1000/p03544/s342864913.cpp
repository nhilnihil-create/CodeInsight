#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int64_t L0 = 2LL;
  int64_t L1 = 1LL;
  int64_t L2 = 1LL;

  for(int i = 1; i < N; i++)
  {
    L2 = L0 + L1;
    L0 = L1;
    L1 = L2;
  }

  cout << L2 << endl;
  return 0;
}