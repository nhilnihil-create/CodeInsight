#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
const double PI = 3.14159265358979323846;
template <class T, class U>
void chmin(T& t, const U& u) {
  if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
  if (t < u) t = u;
}

int main(void) {
  int N;
  cin >> N;
  int res = 0;
  for (int i = 1; i <= N; i += 2) {
    int cnt = 0;
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) ++cnt;
    }
    if (cnt == 8) ++res;
  }
  cout << res << endl;
  return 0;
}