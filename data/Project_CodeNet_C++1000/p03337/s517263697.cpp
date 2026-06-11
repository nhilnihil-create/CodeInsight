#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
  int a, b;
  cin >> a >> b;
  vector<int> N(3);
  N[0] = a + b;
  N[1] = a - b;
  N[2] = a * b;
  sort(N.begin(), N.end());
  cout << N[2] << endl;
}
