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
  int r, d, x;
  cin >> r >> d >> x;
  vector<int> vec(11);
  vec[0] = x;
  for (int i = 1; i < 11; i++) {
    vec[i] = r*vec[i-1] - d;
  }
  for (int i = 1; i < 11; i++) {
    cout << vec[i] << endl;
  }
  return 0;
}