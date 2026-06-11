#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,y,x = 0,o,z,kai = 0;
  cin >> n >> y;
  
  if(y < n * 1000 || y > n * 10000){
    cout << "-1 -1 -1" << endl;
    kai = 1;
  }
  else{
    
    for(z = n; z >= 0; z--){
      for(o = 0; o <= n - z; o++){
        x = n - o - z;
        if(1000 * x + 5000 * o + 10000 * z == y){
          cout << z << " " << o << " " << x << endl;
          kai = 1;
          break;
        }
      }
      if(kai == 1)break;
    }
    
  }
  if(kai == 0)cout << "-1 -1 -1" << endl;
}