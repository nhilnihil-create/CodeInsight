#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int N;
  cin >> N;

  for (int i = N; i <= 999; i++)
  {
    int buf = i;
    int a = buf % 10;
    buf /= 10;
    int b = buf % 10;
    buf /= 10;
    int c = buf % 10;
    if (a == b && b == c)
    {
      cout << i << endl;
      return 0;
    }
  }
}
