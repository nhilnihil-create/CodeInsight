#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
ll f(ll x) {
  ll num = 0;
  // if (x == 0 || x == 1) return 1;
  if (((x + 1) / 2) % 2 == 1) {
    num += 1;
  }
  if (x % 2 == 0) {
    num += x;
  } else {
  }
  return num;
}
int main() {
  ll A, B;
  cin >> A >> B;
  if (A == B) {
    cout << A << endl;
    return 0;
  }
  cout << (f(A - 1) ^ f(B)) << endl;
}