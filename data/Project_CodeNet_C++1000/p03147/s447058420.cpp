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
  int n;
  cin >> n;
  vector<int> vec(n);
  REP(i, n) {
    cin >> vec[i];
  }
  vector<int> g(n);
  int ans = 0;
  REP(i, n) {
    while(g[i] < vec[i]) {
      int j = i+1;
      while(g[j] < vec[j]) {
        j++;
      }
      for (int k = i; k < j; k++) {
        if (g[k] == vec[k]) break;
        g[k]++;
      }
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}