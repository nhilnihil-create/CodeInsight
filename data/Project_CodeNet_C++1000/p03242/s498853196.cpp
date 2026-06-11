#include <bits/stdc++.h>
using namespace std;

int main(){
  int A;
  cin >> A;
  if(A/100==1){
    cout << 9;
  }
  else{
    cout << 1;
  }
  if((A%100-A%10)/10==1){
    cout << 9;
  }
  else{
    cout << 1;
  }
  if(A%10==1){
    cout << 9;
  }
  else{
    cout << 1;
  }
}