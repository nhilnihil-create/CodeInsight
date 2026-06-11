#include <bits/stdc++.h>
using namespace std;
int main(void){
   
  int r,D,x_i;
  cin >> r >> D >> x_i;
  
  for(int i=0;i<10;i++){
      x_i = r * x_i - D;
      cout << x_i <<endl;
  }
}