#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> A;

  ll a;
  ll sum = 0;
  ll rui[N + 1];
  memset(rui, 0, sizeof(rui));

  for (int i = 0; i < N; ++i) {
    cin >> a;
    sum += a;
    A.push_back(a);
    rui[i + 1] = sum;
  }

  vector<ll> nums;

  for (int len = 1; len <= N; ++len) {
    for (int i = len; i <= N; ++i) {
      ll v = rui[i] - rui[i - len];
      nums.push_back(v);
    }
  }
  
  ll ans = 0;

  for (int s = 63; s >= 0; --s) {
    vector<ll> cand;

    for (int i = 0; i < nums.size(); ++i) {
      ll v = nums[i];

      if ((v >> s & 1) == 1) {
        cand.push_back(v);
      }
    }

    if (cand.size() >= K) {
      ans += pow(2, s);
      nums = cand;
    }
  }

  cout << ans << endl;

  return 0;
}
