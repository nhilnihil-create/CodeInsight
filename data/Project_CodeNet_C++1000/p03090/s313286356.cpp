#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;

signed main() {
  int n;
  cin >> n;

  int cnt = 0;
  vector<pair<int,int>> P;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if(n % 2 == 1 && i + j == n) continue;
      if(n % 2 == 0 && i + j == n + 1) continue;
      P.emplace_back(i,j);
      cnt++;
    }
  }
  
  cout << cnt<< endl;
  for (auto it: P){
    cout << it.first << " " << it.second << endl;
  }
  return 0;
}

