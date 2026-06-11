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
  int n; cin >> n;
  int t[110000], x[110000], y[110000];
  t[0] = x[0] = y[0] =0;
  REP(i,n) cin >> t[i+1] >> x[i+1] >> y[i+1];
  
  bool can = true;
  REP(i,n){
    int dt = t[i+1] - t[i];
    int dist = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
    if (dt < dist) can = false;
    if (dist %2 != dt %2) can = false;
  }
  
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
}