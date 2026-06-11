#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
  char c[3][3];
  rep(i, 3) rep(j, 3) cin >> c[i][j];
  rep(i, 3) cout << c[i][i];
  cout << endl;
  return 0;
}