#include <bits/stdc++.h>
using namespace std;

int main() {
  int add = 10;
  int ans = 0;
  for(int i = 0; i < 5; i++){
   	int temp; cin >> temp;
    int mod = temp % 10;
	ans += temp - temp%10;
    
	if(mod != 0) {
      ans += 10;
      add = min(add, mod);
    }
  }
  
  ans -= (10 - add);
  
  cout << ans << endl;
  
  
  return 0; 
}