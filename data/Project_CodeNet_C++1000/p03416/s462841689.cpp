#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

bool is_palindromic(int x) {
  string s = to_string(x);

  for (int i = 0; i < s.size() / 2; ++i) {
    if (s[i] != s[s.size() - 1 - i]) return false;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b;
  cin >> a >> b;

  int res = 0;
  for (int x = a; x <= b; ++x) {
    if (is_palindromic(x)) res++;
  }

  cout << res << "\n";
}
