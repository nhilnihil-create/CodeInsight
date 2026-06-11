#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> V(3);
  cin >> V[0] >> V[1] >> V[2];
  sort(V.begin(), V.end());
  int ans, m;
  m=2*V[2]-V[0]-V[1];
  if (m%2==0) {
    ans = m/2;
  }
  else {
    ans = (m+3)/2;
  }
  cout << ans << endl;
}