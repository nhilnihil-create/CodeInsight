#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string n;
  cin >> n;
  
  int ans = 0;
  for(int i = 0; i < 4; i++) if(n.at(i) == '2') ans++;
  
  cout << ans << '\n';
}