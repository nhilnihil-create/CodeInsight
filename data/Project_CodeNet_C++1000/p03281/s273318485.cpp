#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int N;
  cin >> N;

  if (N < 105) {
    cout << 0;
  } else if (N == 105) {
    cout << 1;
  } else {
    int cnt = 0;
    for (int i = 107; i <= N; i += 2) {
      int divi = 0;
      FOR(l, 1, i+1) {
        if (i % l == 0) divi++;
      }
      if (divi == 8) {
        cnt++;
      }
    }
    cout << cnt + 1;
  }
}