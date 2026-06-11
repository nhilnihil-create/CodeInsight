#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  if (t > s)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
