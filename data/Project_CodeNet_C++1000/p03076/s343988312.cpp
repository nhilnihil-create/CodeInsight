#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
bool sort_by_diff(int a, int b) {
  if (a % 10 == 0) {
    return true;
  }
  if (b % 10 == 0) {
    return true;
  }
  return 10 - a % 10 < 10 - b % 10;
}
int main()
{
  vector<int> vec(5);
  REP(i, 5) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end(), sort_by_diff);
  int ans = 0;
  REP(i, 4) {
    if (vec[i] % 10 == 0)  {
      ans += vec[i];
    } else {
      ans += vec[i] + (10 - (vec[i] % 10));
    }
  }
  ans += vec[4];
  cout << ans << endl;
  return 0;
}