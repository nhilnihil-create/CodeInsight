#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s;
  int a,b;
  cin >> a >> b >> s;
  s[b - 1] = s[b - 1]  - 'A' + 'a';
  cout << s << endl;
  return 0;
}
