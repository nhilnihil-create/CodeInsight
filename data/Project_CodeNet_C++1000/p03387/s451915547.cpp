#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  int sum = A+B+C;
  int maxABC = max(A, max(B,C));
  int ans;
  if ((maxABC % 2) == (sum % 2)) ans = (maxABC*3 - sum)/2;
  else ans = ((maxABC+1)*3 - sum)/2;
  cout << ans << endl;
  return 0;
}