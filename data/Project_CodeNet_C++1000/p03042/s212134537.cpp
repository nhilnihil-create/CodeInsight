#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  int S;
  cin >> S;
  if (S / 100 <= 12 && S/100 >= 1) {
    if (S - S / 100 * 100 <= 12 && S - S / 100 * 100 >= 1) {
      cout << "AMBIGUOUS" << endl;
    } else {
      cout << "MMYY" << endl;
    }
  } else {
    if (S - S / 100 * 100 <= 12 && S - S / 100 * 100 >= 1) {
      cout << "YYMM" << endl;
    } else {
      cout << "NA" << endl;
    }
  }
}