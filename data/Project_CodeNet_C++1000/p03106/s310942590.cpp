#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,k;
  cin >> a >> b >> k;
  
  int res = 0;
  int c = 0;
  
  for(int i = min({a,b}); i > 0; --i){
    if(a % i == 0 && b % i == 0){
      c += 1;
    }
    if(c == k){
      res = i;
      break;
    }
  }
  
  cout << res << endl;
}