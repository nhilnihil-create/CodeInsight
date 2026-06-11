#include<bits/stdc++.h>
using namespace std;

int main (void){
  int a = 0,b = 0;

  cin >> a >> b;

  if(a % 2 == 0 || b % 2 == 0){
    cout << "Even\n";
  }else{
    cout << "Odd";
  }

  return 0;
}