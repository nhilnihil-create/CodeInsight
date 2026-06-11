#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  int x = (1800 * m + 100 * n) * pow(2, m);
  cout << x << endl;
  return 0;
}