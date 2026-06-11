#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  string S;
  cin >> S;
  int countB = 0;
  int countW = 0;
  for (int i = 0; i < S.size(); i++) {
    if ((S[i] == '0' && i % 2 == 0) || (S[i] == '1' && i % 2 != 0)) {
      countB++;
    } else {
      countW++;
    }
  }
  cout << min(countB, countW) << endl;
}