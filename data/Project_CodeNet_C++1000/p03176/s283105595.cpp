/**
 *    author:  math2do
 *    created: 09.09.2020 00:48:18
**/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
 public:
  vector <T> bit;
  vector <T> arr;
  int init = 0;
  int n;
  fenwick(int _n) : n(_n + 1) { 
    arr = vector <T>(n, init);
    bit = vector <T>(n, init);
  }

  fenwick(vector <int>& nums) : fenwick(nums.size()) {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      modify(i, nums[i]);
    }                      
  }

  void modify(int i, T val) { 
    int idx = i + 1;
    while (idx < n) {
      bit[idx] = max(bit[idx], val);
      idx = idx + (idx & -idx);
    }
    arr[i] = val;
  }

  T get(int i) {
    T res = init;
    int idx = i + 1;
    while (idx > 0) {
      res = max(res, bit[idx]);
      idx = idx - (idx & -idx);
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> h(n);
  vector <int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  } 
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  } 
  vector <long long> dp(n + 1, 0);
  fenwick <long long> fn(n + 1);
  for (int i = 0; i < n; i++) {
    long long good = fn.get(h[i] - 1);
    long long dec = max(dp[h[i]], good + b[i]);
    if (dec > dp[h[i]]) {
      fn.modify(h[i], dec);
      dp[h[i]] = dec;
    } 
  }

  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, dp[i]);
  } 
  cout << ans << endl;
  return 0;
}
