#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(n+1);
  for(int i = 0; i < m; i++){
    int k;
    cin >> k;
    a.at(k)++;
  }
  
  int ans = 0, cnt = 0;
  for(int i = x; i < n; i++) ans += a.at(i);
  for(int i = x; i > 0; i--) cnt += a.at(i);
  ans = min(ans, cnt);
    
  cout << ans << endl;
}