#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int X,f_X,X_r = 10;
  
  cin >> X;
  f_X = X%10;
  
  rep(i,8) {
    X_r *= 10;
       f_X += (X%X_r)/(X_r/10);
    }
  
  if (X%f_X == 0){
     cout << "Yes" << endl;
   }
   else{
     cout << "No" <<endl;
   }
    
  
}