#include <bits/stdc++.h>
using namespace std;

int main () {
  string S;
  cin >> S;
  int N = S.length(), cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '0') cnt1++;
    else cnt2++;
  }
  cout << 2 * min(cnt1, cnt2) << endl;
}
