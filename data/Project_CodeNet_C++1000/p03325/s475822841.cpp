#include <bits/stdc++.h>
using namespace std;
 
int count(int x){
  int counter = 0;
  while(x%2 == 0){
    counter++;
    x /= 2;
  }
  return counter;
}
 
int main(){
  int n, y;
  cin >> n;
  int ans = 0;
  for(int i = 0; i < n; ++i){
      cin >> y;
      if(y%2 == 0) ans += count(y);
  }
  cout << ans << '\n';
}