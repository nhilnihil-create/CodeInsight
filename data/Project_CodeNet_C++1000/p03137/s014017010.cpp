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
  int N, M;
  cin >> N >> M;
  vector<ll> seq(M);
  vector<ll> d(M-1);
  REP(i, M) {
    cin >> seq[i];
  }
  if (N >= M) {
    cout << 0 << endl;
    return 0;
  }
  sort(seq.begin(), seq.end());
  REP(i, M-1) {
    d[i] = abs(seq[i+1] - seq[i]);
  }
  sort(d.begin(), d.end());
  ll ans = 0;
  while (N > 1) {
    d.pop_back();
    N--;
  }
  REP(i, d.size()) {
    ans += d[i];
  }
  
  cout << ans << endl; 
}