#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int ver = 1;
  for(int i = 0; i < n - 1; i++)
  {
    if(s[i] != s[n - 2 - i]) ver = 0;
  }
  if(s[0] == '0' || s[n - 1] == '1' || ver == 0)
  {
    cout << "-1" << endl;
    return 0;
  }
  s[n - 1] = '1';
  vector<int> p(n, 0);
  for(int i = 0, j = 0; i < n; i = j)
  {
    for(j = i + 1; j < n && s[j] == '0'; j++);
    if(j == n) break;
    for(; i < j; i++)
    {
      p[i] = j;
    }
  }
  for(int i = 0; i < n - 1; i++)
  {
    cout << i + 1 << " " << p[i] + 1 << endl;
  }
  return 0;
}
