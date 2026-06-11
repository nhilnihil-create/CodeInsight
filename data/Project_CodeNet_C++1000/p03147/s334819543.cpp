#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  int m = 0, ans = 0;
  for(int i = 0;i < n;i++){
    cin >> a[i];
    m = max(m,a[i]);
  }
  
  bool b = false;
  for(int i = 1;i <= m;i++){
    for(int j = 0;j < n;j++){
      if(!b && a[j] >= i) b = true;
      if(b && a[j] < i){
        b = false;
        ans++;
      }
    }
    if(b) {
      ans++;
      b = false;
    }
  }
  
  cout << ans << endl;
  return 0;
}