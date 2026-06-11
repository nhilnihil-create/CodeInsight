#include<bits/stdc++.h>

using namespace std;

int main()
{
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  if(t <= s) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}