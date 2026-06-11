#include <bits/stdc++.h>

#define INF 0x3FFFFFFF

using namespace std;

int counter[26][200000], dp[1 << 26], opt[200001];

int getHash(int idx) {
  int result = 0;
  for (int i = 0; i < 26; i++) if (counter[i][idx] & 1) result |= 1 << i;
  return result;
}

void update(int hash, int val) {
  if (dp[hash] == -1 || val < dp[hash]) dp[hash] = val;
}

int numberOfSetBits(int i) {
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int n = s.size();

  for (int i = 0; i < n; i++) {
    if (i) for (int j = 0; j < 26; j++) counter[j][i] = counter[j][i - 1];
    counter[s[i] - 'a'][i]++;
  }
  
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  opt[0] = 0;
  for (int i = 1; i <= n; i++) {
    opt[i] = INF;
    int thisHash = getHash(i - 1);
    if (numberOfSetBits(thisHash) <= 1) {
      opt[i] = 1;
    }
    for (int j = 0; j < 26; j++) {
      int otherHash = thisHash ^ (1 << j);
      int otherVal = dp[otherHash];
      if (otherVal != -1) {
        opt[i] = min(opt[i], otherVal + 1);
      }
    }
    update(thisHash, opt[i]);
  }

  cout << opt[n] << endl;
  return 0;
}
