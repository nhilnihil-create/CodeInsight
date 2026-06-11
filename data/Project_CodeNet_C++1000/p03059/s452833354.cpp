#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main()
{
  int a,b,t;
  cin >> a >> b >> t;
  int ans = 0;
  int time = a;
  while(time<=t){
    ans += b;
    time += a;
  }
  cout << ans << '\n';
  return 0;
}