#include <bits/stdc++.h>
using namespace std;

int main()
{
  int cnt = 0;
  string S;
  cin >> S;
  for (int i = 0; i < S.size(); i++)
  {
    if (S.at(i) == 'o')
      cnt++;
  }
  cout << ((cnt + (15 - S.size()) >= 8) ? "YES" : "NO") << endl;
}
