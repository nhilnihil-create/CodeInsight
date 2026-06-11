#include <bits/stdc++.h>
using namespace std;
 
int main() { 
  int abc , d ;
  cin>> abc ;
  d=0;
  if (abc==111){
   d=3;
  }
  else if (abc==110||abc==101||abc==11){ 
    d=2;
  }
  else if (abc==100||abc==10||abc==1){
    d=1;
  }
  else{
    d=0;
  }
  cout << d << endl;
}