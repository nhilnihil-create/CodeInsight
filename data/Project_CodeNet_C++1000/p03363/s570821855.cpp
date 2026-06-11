#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];

  vector<long long> s(N + 1, 0);
  map<long long, long long> nums;
  for (int i = 0; i < N; ++i) s[i + 1] = s[i] + a[i];
  for (int i = 0; i < N + 1; ++i) nums[s[i]]++;

  long long res = 0;
  for (auto it : nums) {
    long long num = it.second;
    res += num * (num - 1) / 2;
  }
  cout << res << endl;
  return 0;
}
