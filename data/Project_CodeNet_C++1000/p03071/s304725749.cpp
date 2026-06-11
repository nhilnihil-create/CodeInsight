#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  
  int ans = 0;
  ans += max(a, b);
  if(a < b) b--;
  else a--;
  ans += max(a, b);
  
  cout << ans << endl;
  
  return 0;
}