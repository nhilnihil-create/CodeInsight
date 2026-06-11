#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "YES" : "NO");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int A, B, X;
  cin >> A >> B >> X;
  printYesNo(A <= X && X <= A + B);
  return 0;
}