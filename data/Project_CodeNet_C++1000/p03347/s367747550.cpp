#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  if(a.at(0) != 0){
    cout << -1 << '\n';
    return 0;
  }
  
  for(int i = 0; i < n - 1; i++){
    if(a.at(i) + 1 < a.at(i + 1)){
      cout << -1 << '\n';
      return 0;
    }
  }
  
  long long ans = 0, keep;
  for(int i = n - 1; i >= 0; i--){
    keep--;
    if(a.at(i) > keep){
      ans += a.at(i);
      keep = a.at(i);
    }
  }
  
  cout << ans << '\n';
}