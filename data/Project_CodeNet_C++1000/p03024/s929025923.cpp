#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  string s;
  cin >> s;

  if (count(s.begin(), s.end(), 'o') + 15 - s.length() >= 8)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}