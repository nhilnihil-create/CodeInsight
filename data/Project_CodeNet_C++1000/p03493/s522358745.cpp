#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  int b = 0;  
  cin>>a; 
  for(int i=0;i<3;i++){
    if(a%2 == 1){
      b= b+1;
    }
    a=a/10;    
  }
  cout<< b << endl;
}