#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);

  for (int i = 0; i < n; i++) {
      cin >> a[i];
  }

  vector<long long> b(n+1);
  b[0] = 0;

  for (int i = 1; i < n+1; i++) {
      b[i] = b[i-1]+a[i-1];
  }

  map<long long, long long> nums;
  for (int i = 0; i < n+1; i++) {
      nums[b[i]]++;
  }

  long long res = 0;
  for (auto it : nums) {
      long long num = it.second;
      res += num * (num - 1) / 2;
  }

  cout << res << endl;

}
