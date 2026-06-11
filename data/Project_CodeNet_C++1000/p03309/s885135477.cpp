#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define printYes() cout << "Yes" << endl;
#define printNo() cout << "No" << endl;
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N)
  {
    cin >> A[i];
    A[i] -= (i + 1);
  }
  sort(A.begin(), A.end());

  long long a = A[N / 2];
  long long b = A[N / 2 - 1];
  long long sum1 = 0;
  long long sum2 = 0;
  rep(i, N)
  {
    sum1 += abs(A[i] - a);
    sum2 += abs(A[i] - b);
  }
  long long ans = min(sum1, sum2);
  cout << ans << endl;
  return 0;
}