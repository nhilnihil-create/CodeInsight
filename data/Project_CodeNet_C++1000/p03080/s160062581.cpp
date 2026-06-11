#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, count = 0, count1 = 0;
  cin >> N;
  string S;
  cin >> S;
  for (int i = 0; i < N; i++)
  {
    if (S.at(i) == 'R')
    {
      count++;
    }
    else
    {
      count1++;
    }
  }
  if (count1 < count)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
