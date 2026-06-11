#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int cr = (n-1)/2;
  int cl = n-cr-1;
  char d = s[cr];
  char r = s[cr];
  char l = s[cl];
  int ans = cl;
  while (r == d && l == d) { 
    ++ans;
    --cr;
    ++cl;
    if (cr < 0 || cl >= n) break;
    r = s[cr];
    l = s[cl];
  }
  cout << ans << endl;
}

