#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  if(s[0] == t[2] && s[1] == t[1] && s[2] == t[0]) cout << "YES\n";
  else cout << "NO\n";
}