#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  int x[n], y[m];
  REP(i, n) cin >> x[i];
  REP(i, m) cin >> y[i];

  for (int z = X + 1; z <= Y; ++z) {
    int c = 0;
    REP(i, n) if (x[i] < z) ++c;
    REP(i, m) if (y[i] >= z) ++c;
    if (c == n + m) {
      cout << "No War" << endl;
      return 0;
    }
  }
  cout << "War" << endl;
  return 0;
}