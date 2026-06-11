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
  int N, X;
  cin >> N;
  vector<int> vec(N);
  vector<int> diff(N);
  REP(i, N) {
    cin >> vec[i];
    diff[i] = vec[i] - (i+1);
  }
  sort(diff.begin(), diff.end());
  int sub = diff[N/2];
  if (N % 2 == 0) {
    sub = diff[N/2 -1];
  }
  
  ll ans = 0;
  REP(i, N) {
    ans += abs(diff[i] - sub);
  }
  cout << ans << endl;
  return 0;
}  