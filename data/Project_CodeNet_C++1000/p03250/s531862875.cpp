#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, C;
  cin >> A >> B >> C;

  int m = max({A, B, C});

  if (m == A)
  {
    cout << A * 10 + B + C << endl;
  }
  else if (m == B)
  {
    cout << A + B * 10 + C << endl;
  }
  else
  {
    cout << A + B + C * 10 << endl;
  }
}
