#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  vector<int> cnt;
  if (S[0] == '0') cnt.push_back(0);
  int k = 1;
  rep(i, N) {
    if (i == 0) continue;
    if (S[i] == S[i-1]) {
      k++;
    }
    else {
      cnt.push_back(k);
      k = 1;
    }
  }
  cnt.push_back(k);
  if (S.back() == '0') cnt.push_back(0);
  int s = cnt.size();
  
  vector<int> cumsum(s);
  rep(i, s) {
    if (i == 0) cumsum[i] = cnt[i];
    else cumsum[i] = cumsum[i-1] + cnt[i];
  }
  int ans = cumsum[0];
  for (int i = 0; i <= 2*K; i += 2) {
    if (i >= s) continue;
    ans = max(ans, cumsum[i]);
  }
  for (int i = 1; i < s; i += 2) {
    if (i + 2*K + 1 < s) {
      ans = max(ans, cumsum[i + 2*K + 1] - cumsum[i]);
    }
    else {
      ans = max(ans, cumsum[s-1] - cumsum[i]);
    }
  }
  cout << ans << endl;
}