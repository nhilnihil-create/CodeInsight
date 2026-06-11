#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if(a + b > 2 * c){
    if(x > y){
      ans += y * 2 * c;

      if(a>2*c){
        ans += (x - y) * 2 * c;
      }else{
        ans += (x - y) * a;
      }
    }else{
      ans += x * 2 * c;
      
      if(b>2*c){
        ans += (y - x) * 2 * c;
      }else{
        ans += (y - x) * b;
      }
    }
  }else{
     if(a>2*c){
       ans += x * 2 * c;
     }else{
       ans += x * a;
     }
     if(b>2*c){
       ans += y * 2 * c;
     }else{
       ans += y * b;
     }
  }
  cout << ans << "\n";
  return 0;
}