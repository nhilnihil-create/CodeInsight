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
  int N;
  cin >> N;
  long double ans = 0;
  vector<ll> vec;
  REP(i, N) {
    long double x;
    string v;
    cin >> x >> v;
    if (v == "BTC") {
      ans += 380000 * x;
    } else {
      ans += x;
    }
  }
  cout << ans << endl;
  
  return 0;
}