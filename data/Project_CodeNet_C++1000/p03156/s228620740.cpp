#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
  int n,a,b;
  cin >> n >> a >> b;
  vector<int> p(n);
  REP(i,n) cin >> p[i];
  sort(ALL(p));
  int q1 = distance(p.begin(),upper_bound(ALL(p),a));
  int q2 = distance(p.begin(),upper_bound(ALL(p),b)) - q1;
  int q3 = n - (q2+q1);

  cout << min(q1, min(q2, q3))<< endl;
  return 0;
}
