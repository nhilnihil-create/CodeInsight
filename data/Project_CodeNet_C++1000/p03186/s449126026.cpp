#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t A, B, C, res = 0;
  cin >> A >> B >> C;
  if (C <= A + B + 1)
  {
    res += C;
  }
  else
  {
    res += A + B + 1;
  }
  res += B;
  cout << res << endl;
}
