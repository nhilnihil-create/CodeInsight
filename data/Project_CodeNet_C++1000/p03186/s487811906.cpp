#include <bits/stdc++.h>
using namespace std;

int a,b,c;
int main(){
  cin >> a >> b >> c;
  if (b < c){
    if (c-b <= a){
      cout << 2*b+(c-b);
    }
    else{
      cout << 2*b + a +1;
    }
  }
  else{
    cout << b+c;
  }
  
  return 0;
}
    
   