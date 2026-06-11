#include <bits/stdc++.h>
using namespace std;

int main() {
  int M;
  
  cin >> M;
  if(0 <= M && 24 >= M){
   cout << 24 + (24 - M) << endl;
  }else{
   cout << "Please input number 0 to 24." << endl; 
  }
 }