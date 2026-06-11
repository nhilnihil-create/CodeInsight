#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n, t;
  cin >> n >> t;
  int cc = INF;
  bool ok = false;
  rep(i, n) {
    int c, tm;
    cin >> c >> tm;
    if (t >= tm) {
      ok = true;
      cc = min(cc, c);
    }
  }
  if (ok) {
    cout << cc << endl;
  } else {
    cout << "TLE" << endl;
  }
  
  return 0;
}