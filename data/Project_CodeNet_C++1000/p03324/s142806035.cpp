#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int d, n;
  cin >> d >> n;
  if (n == 100) ++n;
  rep(i, d) n *= 100;
  cout << n << endl;
  return 0;
}