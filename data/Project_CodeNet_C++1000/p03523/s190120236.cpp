#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

bool func(string s){
  if (s.size() >= 9) return s == "AKIHABARA";
  for (int i = 0; i <= s.size(); i++) {
    if(func(s.substr(0, i) + 'A' + s.substr(i))) return true;
  }
  return false;
}

int main() {
  string s;
  cin >> s;
  if (func(s) == true) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}