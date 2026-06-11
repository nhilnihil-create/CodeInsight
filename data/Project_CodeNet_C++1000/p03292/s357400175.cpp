#include <bits/stdc++.h>

using namespace std;

int main (void) {
  int A, B, C;
  cin >> A >> B >> C;
  int cand1 = abs(A-B);
  int cand2 = abs(B-C);
  int cand3 = abs(C-A);
  int ans1 = cand1 + cand2;
  int ans2 = cand2 + cand3;
  int ans3 = cand3 + cand1;
  int ans = min(ans1, min(ans2, ans3));
  cout << ans << endl;
  return 0;
}