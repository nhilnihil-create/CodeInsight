#include<bits/stdc++.h>

using namespace std;

int main(){
  
  int a,b;
  
  cin >> a;
  cin >> b;
  
  if((a+b) %2){
  a = a + 1;
  }
  cout << (a+b)/2 <<endl;

}