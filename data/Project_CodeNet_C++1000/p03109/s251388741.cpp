#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string s;
  cin >> s;
  int m,d;
  m = stoi(s.substr(5,2));
  bool ans = false;
  if(m > 4) ans = true;
  puts(ans?"TBD":"Heisei");
}
  
