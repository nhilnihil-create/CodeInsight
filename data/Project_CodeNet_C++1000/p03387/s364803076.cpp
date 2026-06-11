#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int a = 0, b = 0;
  ll ans = 0;
  if (A % 2 == 1)
    a++;
  else
    b++;
  if (B % 2 == 1)
    a++;
  else
    b++;
  if (C % 2 == 1)
    a++;
  else
    b++;
  if (A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
  } else if (A % 2 == 1 && B % 2 == 1 && C % 2 == 1) {
  } else if (a == 2) {
    ans++;
    if (A % 2 == 0) {
      B++;
      C++;
    } else if (B % 2 == 0) {
      A++;
      C++;
    } else {
      A++;
      B++;
    }
  } else {
    ans++;
    if (A % 2 == 1) {
      B++;
      C++;
    } else if (B % 2 == 1) {
      A++;
      C++;
    } else {
      A++;
      B++;
    }
  }
  ll mx = max(A, max(B, C));
  ll num = mx * 3 - A - B - C;
  ans += num / 2;
  cout << ans << endl;
}