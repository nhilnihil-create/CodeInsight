#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> cm(0);
  vector<int> cp(0);
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    if(a < 0) cm.push_back(-a);
    else cp.push_back(a);
  }
  
  int ans = pow(10, 9);
  int ml = cm.size(), pl = cp.size();
  if(ml) reverse(cm.begin(), cm.end());
  if(ml >= k) ans = min(ans, cm.at(k-1));
  if(pl >= k) ans = min(ans, cp.at(k-1));
  for(int i = 1; i < k-1; i++){
    if(i > ml || k-i > pl) continue;
    int a = cm.at(i-1), b = cp.at(k-i-1);
    int sum = a + b + min(a, b);
    ans = min(ans, sum);
  }
  
  cout << ans << endl;
}