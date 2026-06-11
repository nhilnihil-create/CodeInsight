#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int64_t> C(N - 1), S(N - 1), F(N - 1);
  for (int i = 0; i < N - 1; i++)
  {
    cin >> C.at(i) >> S.at(i) >> F.at(i);
  }
  for (int i = 0; i < N - 1; i++)
  {
    int64_t t = 0;
    for (int j = i; j < N - 1; j++)
    {
      int64_t nextf = F.at(j) * ((t + F.at(j) - 1) / F.at(j));
      t = max(S.at(j), nextf);
      t += C.at(j);
    }
    cout << t << endl;
  }
  cout << 0 << endl;
}
