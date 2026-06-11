#include <bits/stdc++.h>
using namespace std;
int main() {
 int a;
  int count = 0;
  cin >> a;
  for(int i=0;i<26;i++){
   for(int j=0;j<15;j++){
     int total = i*4 + j*7;
     if(total==a){
       count++;
       break;
     }
     if(total>101){
      break;
     }
   }
  }
  if(count==0){
  cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
}