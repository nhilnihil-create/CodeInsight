#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<pair<int, int>> ans;
  for(int i = 1; i < n; i++){
    for(int j = i + 1; j <= n; j++){
      if(i + j != n + !(n % 2)) ans.push_back(make_pair(i, j));
    }
  }
  
  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++) cout << ans.at(i).first << " " << ans.at(i).second << '\n';
}