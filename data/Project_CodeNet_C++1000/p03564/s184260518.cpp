#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a=1;
  int keisansu;
  int b;
   
  cin >> keisansu >>b;
  
  for (int i = 0; i < keisansu; i++) {
    if(a<=b){
      a*=2;}else{   
             a+=b;
           }
  }
  
  cout <<a <<endl;}