#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using M = map<int, int>;
ll INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  char x, y;
  cin >> x >> y;
  if (x < y) cout << "<" << endl;
  else if (x == y) cout << "=" << endl;
  else cout << ">" << endl;


  return 0;
}
