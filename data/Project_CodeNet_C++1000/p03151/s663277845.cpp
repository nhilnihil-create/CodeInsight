#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, sa = 0, sb = 0, minus = 0, cnt = 0;
  cin >> N;
  vector<int64_t> A(N), B(N), D(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    sa += A.at(i);
  }
  for (int i = 0; i < N; i++)
  {
    cin >> B.at(i);
    sb += B.at(i);
    D.at(i) = A.at(i) - B.at(i);
    if (D.at(i) < 0)
    {
      minus += D.at(i);
      cnt++;
    }
  }
  if (sb > sa)
  {
    cout << -1 << endl;
    return 0;
  }
  sort(D.begin(), D.end());
  for (int i = N - 1; i >= 0; i--)
  {
    if (minus >= 0)
      break;
    minus += D.at(i);
    cnt++;
  }
  cout << cnt << endl;
}