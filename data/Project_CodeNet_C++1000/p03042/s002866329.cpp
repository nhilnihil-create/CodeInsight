#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  string S;
  cin >> S;
  bool f = false, g = false;

  int a = (S[0] - '0') * 10 + (S[1] - '0');
  int b = (S[2] - '0') * 10 + (S[3] - '0');

  if (1 <= a && a <= 12) f = true;
  if (1 <= b && b <= 12) g = true;

  if (f && g) {
    cout << "AMBIGUOUS" << endl;
  } else if (f) {
    cout << "MMYY" << endl;
  } else if (g) {
    cout << "YYMM" << endl;
  } else {
    cout << "NA" << endl;
  }
}