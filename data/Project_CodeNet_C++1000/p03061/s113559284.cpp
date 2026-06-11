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
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<int> g1(n+1), g2(n+1);
  g1[0] = 0;
  REP(i,n) g1[i+1] = gcd(g1[i], a[i]);
  g2.back() = 0;
  REPR(i,n-1) g2[i] = gcd(g2[i+1], a[i]);
  
  int ans = 0;
  REP(i,n){
    ans = max(ans, gcd(g1[i], g2[i+1]));
  }
  cout << ans << '\n';
  return 0;
}