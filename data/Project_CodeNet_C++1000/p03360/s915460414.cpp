#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  int ans = 0;
  int a = min(A, B);
  int b = max(A, B);
  A = a;
  B = b;
  b = min(B, C);
  int c = max(B, C);
  B = b;
  C = c;
  a = min(A, B);
  b = max(A, B);
  A = a;
  B = b;
  rep(i, X) {
    C *= 2;
  }
  cout << A + B + C << endl;
}
