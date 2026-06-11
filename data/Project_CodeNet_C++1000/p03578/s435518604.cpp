#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int d; cin >> d;
    mp[d]++;
  }
  int m; cin >> m;
  bool ok = true;
  for(int i = 0; i < m; i++) {
    int t; cin >> t;
    mp[t]--;
    if(mp[t] < 0) ok = false;
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}