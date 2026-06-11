#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
  vector<int> x(3);
  cin >> x[0] >> x[1] >> x[2];
  sort(x.begin(), x.end());
  cout << x[0] * x[1] / 2 << endl;

  return 0;
}