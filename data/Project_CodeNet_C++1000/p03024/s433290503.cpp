#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int k = s.size();
  int ans = 15 - k;
  for(int i = 0; i < k; i++){
    if(s.at(i) == 'o') ans++;
  }
  
  if(ans >= 8) cout << "YES" << endl;
  else cout << "NO" << endl;
}