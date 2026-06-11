#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string S;
  cin >> S;
  int N = (int)(S.size());
  ll DP[N+1][3];
  ll three[100300];
  three[0] = 1;
  for (int i = 1; i < 100300; i++) {
    three[i] = three[i-1] * 3;
    three[i] %= Mod;
  }
  DP[0][0] = 0;
  DP[0][1] = 0;
  DP[0][2] = 0;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'A') {
      DP[i+1][0] = DP[i][0];
      DP[i+1][1] = DP[i][1];
      DP[i+1][2] = DP[i][2];
      DP[i+1][0] += three[cnt];
      DP[i+1][0] %= Mod;
    } else if (S[i] == 'B') {
      DP[i+1][0] = DP[i][0];
      DP[i+1][1] = DP[i][1];
      DP[i+1][2] = DP[i][2];
      DP[i+1][1] += DP[i+1][0];
      DP[i+1][1] %= Mod;
    } else if (S[i] == 'C') {
      DP[i+1][0] = DP[i][0];
      DP[i+1][1] = DP[i][1];
      DP[i+1][2] = DP[i][2];
      DP[i+1][2] += DP[i+1][1];
      DP[i+1][2] %= Mod;
    } else {
      DP[i+1][0] = DP[i][0] * 3;
      DP[i+1][1] = DP[i][1] * 3;
      DP[i+1][2] = DP[i][2] * 3;
      DP[i+1][0] += three[cnt];
      DP[i+1][1] += DP[i][0];
      DP[i+1][2] += DP[i][1];
      DP[i+1][0] %= Mod;
      DP[i+1][1] %= Mod;
      DP[i+1][2] %= Mod;
      cnt++;
    }
  }
  cout << DP[N][2] << endl;
  return 0;
}