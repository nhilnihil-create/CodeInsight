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
  string S;
  cin >> S;
  vector<char> vec(S.size());
  REP(i, S.size()) {
    vec[i] = S[i];
  }
  int ans = 0;
  REP(i, S.size() - 1) {
    if (vec[i] != vec[i+1]) {
      vec[i+1] = vec[i+1];
    } else {
      vec[i+1] = vec[i+1] == '0' ? '1' : '0';
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}