#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int r, D, x;
  cin >> r >> D >> x;

  rep(_,10) {
    x = r * x - D;
    cout << x << endl;
  }
  return 0;
}
