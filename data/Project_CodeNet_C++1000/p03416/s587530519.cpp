#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b;
  cin >> a >> b;
  int e = 0;
  for (int i = a; i <= b; ++i) if (i / 10000 == i % 10 && i % 10000 / 1000 == i % 100 / 10) ++e;
  cout << e << endl;
  return 0;
}