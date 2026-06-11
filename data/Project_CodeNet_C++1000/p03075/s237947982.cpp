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
  vector<int> vec(5);
  int k;
  REP(i, 5) {
    cin >> vec[i];
  }
  cin >> k;
  REP(i, 5) {
    REP(j, 5) {
      if (i == j) {
        continue;
      }
      if (k < abs(vec[i] - vec[j])) {
        cout << ":(" << endl;
        return 0;
      }
    }
  }
  cout << "Yay!" << endl;
  return 0;
}