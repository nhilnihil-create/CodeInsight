#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
  int a,b;
  cin >> a >> b;
  
  string s;
  cin >> s;
  
  if(a + b + 1 == s.size() && s[a] == '-' && s[a - 1] != '-' && s[a + 1] != '-')cout << "Yes" << endl;
  else cout << "No" << endl;
}