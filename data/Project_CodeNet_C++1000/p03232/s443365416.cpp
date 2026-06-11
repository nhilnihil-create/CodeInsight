#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;
const int64_t M = 1000000007;
int n;
int64_t pr_psum[MAX_N+1];

int64_t mod_pow(int64_t a, int64_t b)
{
  if (b == 0) return 1;
  int64_t ret = mod_pow(a, b/2);
  ret = ret * ret % M;
  if (b % 2 == 1) ret = a * ret % M;
  return ret;
}

int main()
{
  cin >> n;
  pr_psum[0] = 0;
  for (int i = 1; i <= n; i++) {
    pr_psum[i] = (pr_psum[i-1] + mod_pow(i, M-2)) % M;
  }

  int64_t fn = 1;
  for (int i = n; i >= 1; i--) {
    fn = (fn * i) % M;
  }

  int a;
  int64_t cost = 0;
  for (int j = 1; j <= n; j++) {
    cin >> a;
    int64_t pr = (pr_psum[n-j+1] - pr_psum[1] + pr_psum[j] - pr_psum[0]) % M;
    cost = (cost + pr * a % M) % M;
  }
  cout << fn * cost % M << endl;

  return 0;
}
