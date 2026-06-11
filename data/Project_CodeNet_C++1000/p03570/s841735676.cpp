#include <bits/stdc++.h>
#define REP(i, a, n) for(int i = ((int) a); i < ((int) n); i++)
#define INF (1LL << 28)
using namespace std;

string S;
int p[26], h[200000], cnt[26][200000];

int main(void) {
  cin >> S;

  REP(i, 0, 26) p[i] = pow(2, i);

  REP(i, 0, 26) REP(j, 0, S.length()) cnt[i][j] = 0;
  REP(i, 0, S.length()) cnt[S[i] - 'a'][i] = 1;
  REP(i, 0, 26) REP(j, 1, S.length()) cnt[i][j] += cnt[i][j - 1];

  REP(i, 0, S.length()) {
    h[i] = 0;
    REP(k, 0, 26) if(cnt[k][i] & 1) h[i] ^= p[k];
  }

  vector<int> dp(1 << 26, INF);
  dp[0] = 0;
  vector<int> ans(S.length(), INF);

  REP(i, 0, S.length()) {
    ans[i] = min(ans[i], dp[h[i]] + 1);
    REP(k, 0, 26) ans[i] = min(ans[i], dp[h[i] ^ p[k]] + 1);
    dp[h[i]] = min(dp[h[i]], ans[i]);
  }
  cout << ans[(int) S.length() - 1] << endl;
}
