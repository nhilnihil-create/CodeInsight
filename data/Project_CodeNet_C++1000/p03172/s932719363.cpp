/**
 *    author:  math2do
 *    created: 05.09.2020 14:31:48
**/

#include <bits/stdc++.h>

using namespace std;

const int mod = (int) (1e9 + 7);

inline void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  } 
  vector <int> dp(k + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    vector <int> temp(k + 1);
    for (int c = k; c >= 0; c--) {
      int from = c + 1;
      int to = c + min(arr[i], k - c);
      if (from <= to) {
        add(temp[from], dp[c]);
        if (to + 1 <= k) {
          sub(temp[to + 1], dp[c]);
        }
      } 
    }
    int pre = 0; 
    for (int j = 0; j <= k; j++) {
      add(pre, temp[j]);
      add(dp[j], pre);
    } 
  } 

  cout << dp[k] << endl;
  return 0;
}