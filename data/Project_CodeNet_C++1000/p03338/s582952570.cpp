#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )
 
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  string S;
  cin >> S;

  vector<int> X(26, 0), Y(26, 0);
  REP(i, N) Y[S[i]-'a']++;

  int ans = 0;
  REP(i, N) {
    int now = 0;
    X[S[i]-'a']++;
    Y[S[i]-'a']--;
    REP(j, 26) if ( X[j] && Y[j] ) now++;
    ans = max(ans, now);
  }

  cout << ans << endl;
  
  return 0;
}
