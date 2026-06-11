#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x;
  cin >> x;
  
  int a,b,c,d;
  
  a = x % 10;
  b = x / 10 % 10;
  c = x / 10 / 10 % 10;
  d = x / 10 / 10 / 10 % 10;
  

  
  int count = 0;
 
  if(a == b && a == c){
  	  count = 1;
  }
  
  if(b == c && b == d){
  	  count = 1;
  }
  
  if(count == 1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;

  }

}