#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, a, b, turn = 0, tak = 0, aok = 0;
  cin >> N;
  vector<bool> Used(N, false);
  priority_queue<tuple<int64_t, int64_t, int64_t>> A, B;
  for (int i = 0; i < N; i++)
  {
    cin >> a >> b;
    A.push(make_tuple(a + b, a, i));
    B.push(make_tuple(a + b, b, i));
  }
  int64_t x, y, idx;
  while (turn < N)
  {
    if (turn % 2 == 0)
    {
      while (Used.at(get<2>(A.top())))
        A.pop();
      tie(x, y, idx) = A.top();
      A.pop();
      Used.at(idx) = true;
      tak += y;
    }
    else
    {
      while (Used.at(get<2>(B.top())))
        B.pop();
      tie(x, y, idx) = B.top();
      B.pop();
      Used.at(idx) = true;
      aok += y;
    }
    turn++;
  }
  cout << tak - aok << endl;
}
