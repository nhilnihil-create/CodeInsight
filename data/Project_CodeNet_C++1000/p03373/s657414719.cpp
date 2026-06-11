#include <bits/stdc++.h>
using namespace std;

int a,b,c,x,y;
int main(){
  int total;
  cin >> a >>b>>c>>x>>y;
  if (c*2 >= a+b){
    cout << a*x + b*y;
    return 0;
  }
  
  else{
    total = min(x,y)*c*2;
    if (x>y){
      if (c*2 < a){
        total += (x-y)*2*c;
      }
      else{
        total += (x-y)*a;
      }
    }
    else if(y>x){
      if (c*2 < b){
        total += (y-x)*2*c;
      }
      else{
        total += (y-x)*b;
      }
    }
  }
    
  cout << total;
  return 0;
}
