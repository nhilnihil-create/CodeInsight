#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b[2];
  int count = 0;
  cin >> a;
  b[0] = a - a%100;
  b[1] = a%100 - (a%100)%10;
  b[2] = (a%100)%10;
  if(b[0] == 100){
    count++;
  }
  if(b[1] == 10){
    count++;
  }
  if(b[2] == 1){
    count++;
  }
  
  cout << count;
}