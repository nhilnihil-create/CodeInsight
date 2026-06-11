#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  int count = 0;
  while (1)
  {
    for (int &a : A)
    {
      if ((a % 2) == 1)
      {
        cout << count << endl;
        return 0;
      }
      a /= 2;
    }
    count++;
  }
  cout << count << endl;
}
