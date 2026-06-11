#include <bits/stdc++.h>
using namespace std;


int main()
{
  string s, t;
  cin >> s >> t;
  bool ans = true;
  for(int i = 0; i < s.length(); i++) {
    if (s[i] != t[t.length() - i - 1]) {
      ans = false;
    }
  }
  if (ans) {cout << "YES" << endl;}
  else {cout << "NO" <<endl;}
}