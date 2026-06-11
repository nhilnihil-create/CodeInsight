#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, M;
  cin >> N >> M;
  vector<int64_t> X(M);
  for (int i = 0; i < M; i++)
  {
    cin >> X.at(i);
  }
  sort(X.begin(), X.end());
  if (M == 1 || N >= M)
  {
    cout << 0 << endl;
    return 0;
  }
  vector<int64_t> D;
  for (int i = 1; i < M; i++)
  {
    D.push_back(abs(X.at(i - 1) - X.at(i)));
  }
  sort(D.begin(), D.end());
  cout << accumulate(D.begin(), D.end() - (N - 1), 0) << endl;
}
