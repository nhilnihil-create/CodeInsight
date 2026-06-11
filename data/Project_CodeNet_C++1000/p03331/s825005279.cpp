#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int sumOfDigit(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  int ans = INT_MAX;
  for(int i = 1; i <= n / 2; i++) {
    int j = n - i;
    ans = min(ans, sumOfDigit(i) + sumOfDigit(j));
  }
  cout << ans;
}
