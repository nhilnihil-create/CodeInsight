#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;
  cin >> A >> B >> C;
  
  int total=0;
  
  if(C<=A+B){
    total=B+C;
  }else{
    total=A+2*B+1;
  }
  
  cout << total << endl;
}