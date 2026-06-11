#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  int m;
  cin >> m;
  vector<string> t(m);
  for (int i = 0; i < m; i++){
    cin >> t[i];
  }
  int an = 0;
  for (int i = 0; i < n; i++){
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (s[i] == s[j]) ans++;
    }
    for (int j = 0; j < m; j++){
      if (s[i] == t[j]) ans--;
    }
    an = max(ans, an);
  }
  cout << an << endl;
}
