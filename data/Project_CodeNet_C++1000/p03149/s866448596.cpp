#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  vector<int> n(4);
  for(int i = 0; i < 4; i++) cin >> n.at(i);
  
  sort(n.begin(), n.end());
  
  if(n.at(0) == 1 && n.at(1) == 4 && n.at(2) == 7 && n.at(3) == 9){
    cout << "YES\n";
  }
  else cout << "NO\n";
}