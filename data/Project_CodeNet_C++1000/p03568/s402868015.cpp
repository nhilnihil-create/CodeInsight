#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  int sum = 1, bad = 1;
  rep(i, N)
  {
    cin >> A[i];
    sum *= 3;
    if (A[i] % 2 == 0){  // A[i]偶数のとき、B[i]は奇数（A[i]-1,a[i]+1）
      bad *= 2;
    }
  }
  printf("%d\n", sum - bad);

  return 0;
}