#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, a, b, c, d;
  cin >> N;
  vector<pair<int64_t, int64_t>> A(N), B(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a >> b;
    A.at(i) = make_pair(a, b);
  }
  for (int i = 0; i < N; i++)
  {
    cin >> c >> d;
    B.at(i) = make_pair(c, d);
  }
  vector<vector<bool>> Grid(N, vector<bool>(N, false));
  vector<int64_t> cntA(N, 0), cntB(N, 0);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (A.at(i).first < B.at(j).first && A.at(i).second < B.at(j).second)
      {
        Grid.at(i).at(j) = true;
        cntA.at(i)++;
        cntB.at(j)++;
      }
    }
  }
  int64_t INF = 100000007, SKIP = 100000009;
  vector<vector<int64_t>> Points(N, vector<int64_t>(N, 0));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (Grid.at(i).at(j))
        Points.at(i).at(j) = cntA.at(i) + cntB.at(j) - 1;
      else
        Points.at(i).at(j) = INF;
    }
  }
  int64_t cnt = 0;
  while (true)
  {
    int minp = INF, mini = INF, minj = INF;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (Points.at(i).at(j) == SKIP)
          break;
        if (!Grid.at(i).at(j))
          continue;
        if (Points.at(i).at(j) <= minp)
        {
          minp = Points.at(i).at(j);
          mini = i;
          minj = j;
        }
      }
    }
    if (minp == INF)
      break;
    cnt++;
    for (int i = 0; i < N; i++)
    {
      Points.at(mini).at(i) = SKIP;
      Grid.at(mini).at(i) = false;
      Grid.at(i).at(minj) = false;
    }
    minp = INF;
  }
  cout << cnt << endl;
}
