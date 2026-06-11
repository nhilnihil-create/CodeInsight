#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b;
  string s;
  cin >> a >> b >> s;

  for (int i = 0; i < a; ++i) {
    if (s[i] < '0' || s[i] > '9') {
      cout << "No" << "\n";
      return 0;
    }
  }

  if (s[a] != '-')  {
    cout << "No" << "\n";
    return 0;
  }

  for (int i = a + 1; i < s.size(); ++i) {
    if (s[i] < '0' || s[i] > '9') {
      cout << "No" << "\n";
      return 0;
    }
  }

  cout << "Yes" << "\n";
}
