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
  vector<int> A(N + 2, 0);
  rep(i, N)
  {
    cin >> A[i + 1];
  }
  int sum_price = 0;
  rep(i, N + 2)
  {
    sum_price += abs(A[i] - A[i + 1]);
  }
  vector<int> ans(N);
  rep(i, N)
  {
    ans[i] = sum_price + abs(A[i + 2] - A[i]) - abs(A[i + 2] - A[i + 1]) - abs(A[i + 1] - A[i]);
  }

  printVector(ans);
  return 0;
}