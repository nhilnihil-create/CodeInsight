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
  ll N;
  cin >> N;
  vector<ll> vec(5);
  ll m = 0;
  REP(i, 5) {
    cin >> vec[i];
    if (vec[i] < N) {
      ll tmp = (N + vec[i] - 1) / vec[i];
      m = max(m, tmp);
    }
  }
  if (m != 0) {
    cout << m + 4 << endl;
  } else {
    cout << 5 << endl;
  }

  return 0;
}