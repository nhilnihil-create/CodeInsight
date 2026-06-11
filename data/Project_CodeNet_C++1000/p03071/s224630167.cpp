#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int A, B;
  cin >> A >> B;
  if (A > B) {
    cout << 2*A -1 << endl;
  }
  if (A < B) {
    cout << 2*B - 1 << endl;
  }
  if (A == B) {
    cout << A+B << endl;
  }
}