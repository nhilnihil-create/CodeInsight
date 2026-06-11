#include<bits/stdc++.h>
using namespace std;

int main() {
  string s{'2'};
  int n;
  {
    string t; cin >> t;
    s += t;
    s += '3';
    n = s.size();
  }
  int l = (n + 1) / 2 - 1;
  int r = n - 1 - l;
  char c = s[l];
  for (; s[l] == s[r] && s[l] == c; l--, r++);
  cout << r-1 << endl;
}