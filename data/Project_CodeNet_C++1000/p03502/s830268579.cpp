#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,sum;
  cin >> a;
  c = a;
  b = 0;
  sum = 0;

  for (int i = 0 ; i < 10 ; i++ ){
    b = a % 10;
    sum += b;
    if(a > 9) {
      a /= 10;
    } else {
      break;
    }
   }
    if(c % sum == 0){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;  
  }    
}

