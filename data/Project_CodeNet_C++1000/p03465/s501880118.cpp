#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 2e3 + 5;
const int ZERO = 2e5 + 5e4;
const int MAX_B = 5e5 + 5;

int arr [MAX_N];

vector<char> _last;
char& last (int j) {
  return _last[j + ZERO];
}

vector<char> _dp;
char& dp (int j) {
  return _dp[j + ZERO];
}

int main () {
  int n;
  cin >> n;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  random_shuffle(arr, arr + n);

  _dp = vector<char> (MAX_B, 0);
  dp(0) = 1;
  for (int i = 0; i < n; i++) {
    _last = _dp;
    _dp = vector<char> (MAX_B, 0);
    for (int j = -ZERO; j <= ZERO; j++) {
      if (last(j)) {
        if (j - arr[i] >= -ZERO) {
          dp(j - arr[i]) = 1;
        }
        if (j + arr[i] <= ZERO) {
          dp(j + arr[i]) = 1;
        }
      }
    }
  }

  for (int i = 0; i <= ZERO; i++) {
    if (dp(i)) {
      cout << (sum + i) / 2 << endl;
      return 0;
    }
  }
}
