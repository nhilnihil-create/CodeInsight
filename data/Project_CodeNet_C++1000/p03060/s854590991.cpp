#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main()
{
  int n; cin >> n;
  vector<int> value(n), cost(n);
  REP(i,n) cin >> value[i];
  REP(i,n) cin >> cost[i];
  
  int ans = 0;
  REP(i,n){
    int sub = value[i] - cost[i];
    if(sub>0) ans += sub;
  }
  cout << ans << '\n';
  return 0;
}