#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  if(s.at(k - 1) == 'A') s.at(k - 1) = 'a';
  if(s.at(k - 1) == 'B') s.at(k - 1) = 'b';
  if(s.at(k - 1) == 'C') s.at(k - 1) = 'c';
  cout << s << endl;
}