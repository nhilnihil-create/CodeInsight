#include <bits/stdc++.h>
using namespace std;
const int MAXA = 1000010;

int main()
{
  int64_t N, ma = -MAXA, mi = MAXA, madx, midx;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    ma = max(ma, A.at(i));
    mi = min(mi, A.at(i));
  }
  queue<pair<int, int>> Q;
  if (abs(ma) >= abs(mi))
  {
    auto it = find(A.begin(), A.end(), ma);
    int idx = distance(A.begin(), it);
    for (int i = 0; i < N; i++)
    {
      if (A.at(i) < ma)
      {
        A.at(i) += ma;
        Q.push({idx, i});
      }
      if (i > 0 && A.at(i) < A.at(i - 1))
      {
        A.at(i) += A.at(i - 1);
        Q.push({i - 1, i});
      }
    }
  }
  else
  {
    auto it = find(A.begin(), A.end(), mi);
    int idx = distance(A.begin(), it);
    for (int i = N - 1; i >= 0; i--)
    {
      if (A.at(i) > mi)
      {
        A.at(i) += mi;
        Q.push({idx, i});
      }
      if (i != N - 1 && A.at(i) > A.at(i + 1))
      {
        A.at(i) += A.at(i + 1);
        Q.push({i + 1, i});
      }
    }
  }
  cout << Q.size() << endl;
  while (!Q.empty())
  {
    cout << Q.front().first + 1 << ' ' << Q.front().second + 1 << endl;
    Q.pop();
  }
}
