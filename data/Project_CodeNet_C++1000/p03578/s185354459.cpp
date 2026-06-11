#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    mp[d]++;
  }
  
  int m;
  cin >> m;
  
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (mp[t] == 0) {
      cout << "NO\n";
      return 0;
    }
    else mp[t]--;
  }
  
  cout << "YES\n";
}