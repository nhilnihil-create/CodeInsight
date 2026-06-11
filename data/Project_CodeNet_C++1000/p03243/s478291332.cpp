#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  for (int i = 111; i <= 999; i += 111)
  {
    if (i >= N)
    {
      cout << i << endl;
      return 0;
    }
  }
}
