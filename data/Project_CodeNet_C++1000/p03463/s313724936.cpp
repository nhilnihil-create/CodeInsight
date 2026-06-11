#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, A, B, t = 1;
  cin >> N >> A >> B;
  while (A > 0 && B <= N)
  {
    if (t % 2)
    {
      if (A + 1 == B)
        A--;
      else
        A++;
    }
    else
    {
      if (B - 1 == A)
        B++;
      else
        B--;
    }
    t++;
  }
  cout << ((t % 2) ? "Alice" : "Borys") << endl;
}