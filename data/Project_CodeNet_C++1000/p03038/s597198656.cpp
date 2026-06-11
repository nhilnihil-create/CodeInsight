#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  priority_queue<pair<int, int>> a;
  for(int i = 0; i < n; i++){
    int k;
    cin >> k;
    a.push({k, 1});
  }
  for(int i = 0; i < m; i++){
    int b, c;
    cin >> b >> c;
    a.push({c, b});
  }
  
  int cnt = 0;
  long long ans = 0;
  while(cnt < n){
    auto now = a.top();
    a.pop();
    long long plus = now.first, num = now.second;
    num = min(num, (long long)n - cnt);
    cnt += num;
    ans += plus * num;
  }
  
  
  cout << ans << endl;
}