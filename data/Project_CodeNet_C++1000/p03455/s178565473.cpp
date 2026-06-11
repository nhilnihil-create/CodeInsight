#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  while (a >= 2){
    a = a - 2;
  }
  if (a == 0){
    cout << "Even";
  }
  else {
    while (b >= 2){
      b = b - 2;
    } 
    if (b == 0){
      cout << "Even";
    }
    else{
      cout << "Odd";
    }
  }
}

