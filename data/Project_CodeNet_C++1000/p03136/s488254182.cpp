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
  vector<int> L(N);
  REP(i, N) {
    cin >> L[i];
  }
  int m = 0, s = 0;
  REP(i, N) {
    m = max(m, L[i]);
    s += L[i];
  }
  if ((s - m) > m) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}