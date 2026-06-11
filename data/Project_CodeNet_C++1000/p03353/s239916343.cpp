#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  string s;
  cin >> s >> k;
  vector<string> c(k * s.length());
  for(int i = 0; i < s.length(); i++)
    for(int j = 0; j < k; j++)
      c.at(k * i + j) = s.substr(i, j + 1);
  sort(c.begin(), c.end());
  unique(c.begin(), c.end());
  cout << c.at(k - 1) << endl;
}