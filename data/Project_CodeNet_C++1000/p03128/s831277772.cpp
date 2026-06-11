#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  vector<int> num = {2, 5, 5, 4, 5, 6, 3, 7, 6};
  
  int n, m;
  cin >> n >> m;
  
  vector<int> a(m);
  for(int i = 0; i < m; i++) cin >> a.at(i);
  
  vector<int> dp(n + 10, -1);
  dp.at(0) = 0;
  for(int i = 0; i < m; i++){
    for(int j = num.at(a.at(i) - 1); j <= n; j++){
      if(dp.at(j - num.at(a.at(i) - 1)) != -1){
        dp.at(j) = max(dp.at(j - num.at(a.at(i) - 1)) + 1, dp.at(j));
      }
    }
  }
  
  sort(a.rbegin(), a.rend());
  
  int now = n;
  while(now != 0){
    for(int i = 0; i < m; i++){
      if(now - num.at(a.at(i) - 1) >= 0 && dp.at(now - num.at(a.at(i) - 1)) == dp.at(now) - 1){
        cout << a.at(i);
        now -= num.at(a.at(i) - 1);
        break;
      }
    }
  }
  
  cout << '\n';
}