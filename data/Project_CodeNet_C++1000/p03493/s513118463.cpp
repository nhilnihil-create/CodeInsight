#include <bits/stdc++.h>
using namespace std;

int main()
{
  int count = 0;
  string S;
  cin >> S;
  for (int x = 0; x < 3; x++)
  {
    if (S[x] == '1')
    {
      count++;
    }
  }
  cout << count << endl;
}
