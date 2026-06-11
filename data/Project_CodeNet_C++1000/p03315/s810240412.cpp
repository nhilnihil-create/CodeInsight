#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A = 0;
  char s;
  while (cin >> s)
  {
    if (s == '+')
    {
      A++;
    }
    else if (s == '-')
    {
      A--;
    }
  }
  cout << A << endl;
}
