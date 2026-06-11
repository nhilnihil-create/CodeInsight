#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  int a = 0;
  int mini = 1000;
  
  for (int i = 0; i < N; i++){
    
    int x;
    cin >> x;
    
    
   while(x % 2 == 0){
     a  = a + 1;
     x = x / 2;
   }
   
    //ここでのxの値はしっかり2で割り続けた値
    
    if (mini > a){
      mini = a;
    }
    
    a = 0;
   
   }
  
  cout << mini << endl;
    

 }