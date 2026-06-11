#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int64_t> lucas(N);
  lucas[0] = 2;
  lucas[1] = 1;

  if (N == 0)
  {
    cout << 2 << endl;
    return 0;
  }
  if (N == 1)
  {
    cout << 1 << endl;
    return 0;
  }

  for (int i = 2; i < N + 1; i++)
  {
    lucas[2] = lucas[0] + lucas[1];
    lucas[0] = lucas[1];
    lucas[1] = lucas[2];
  }
  cout << lucas[2] << endl;
}