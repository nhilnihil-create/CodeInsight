#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (INT_MAX / 4)
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
/* clang-format off */
#define TIMER_S(start) chrono::system_clock::time_point start = chrono::system_clock::now();
#define TIMER_E(end) chrono::system_clock::time_point end = chrono::system_clock::now();
#define TIME(start, end) cout << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count()) << "ms" << "\n";
/* clang-format on */

int main() {
  int a,b,c;
  cin >> a >> b;
  if(a<=b)cout << a << "\n";
  else cout << a-1 << "\n";
  return 0;
}
