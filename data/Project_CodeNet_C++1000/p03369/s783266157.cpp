#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 
  
  string s; cin >> s;

  int res = 700;
  for (int i = 0; i < 3; ++i) {
    if (s[i] == 'o') res += 100;
  }
  cout << res << "\n";
}
