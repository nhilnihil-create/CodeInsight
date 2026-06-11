#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,x; cin >> n >> m >> x;
  vector<int> fee(n + 1, 0);
  
 for(int i = 0; i < m; i++) {
    int temp; cin >> temp;
   fee.at(temp)++;
 }
  
 int ans = 0;
 for(int i = x; i > 0; i--){
  ans += fee.at(i); 
 }
  
  int ans2 = 0;
 for(int i = x; i < n; i++){
  ans2 += fee.at(i); 
 }
  
  if(ans < ans2) {
    cout << ans << endl;
  } else {
    cout << ans2 << endl;
  }
  
  return 0; 
}
  