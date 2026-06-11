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
  vector<int> vec(M);
  REP(i, M) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  vector<int> diff(M-1);
  
  REP(i, M-1) {
    diff[i] = abs(vec[i] - vec[i+1]);
  }
  sort(diff.begin(), diff.end());
  int ans = 0;
  REP(i, M-1-(N-1)) {
    ans += diff[i];
  }
  cout << ans << endl;
  return 0;
}