#include <bits/stdc++.h>
using namespace std;

int64_t sum_b(int64_t b, vector<int64_t> vec)
{
  int64_t ret = 0;
  for (size_t i; i < vec.size(); ++i)
  {
    ret += abs(vec[i] - b);
  }
  return ret;
}

int main()
{
  int64_t n, ans = 10e9;
  cin >> n;
  vector<int64_t> A(n);
  for (int i = 0; i < n; ++i)
  {
    int64_t a;
    cin >> a;
    A[i] = a - (i + 1);
  }
  sort(A.begin(), A.end());
  int64_t mean = A[n / 2];
  ans = sum_b(mean, A);

  cout << ans << "\n";
}