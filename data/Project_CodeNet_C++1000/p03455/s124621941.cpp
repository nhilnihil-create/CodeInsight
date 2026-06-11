#include <bits/stdc++.h>
using namespace std;
void check (int num){
  if( num % 2 == 0){
    cout << "Even" << endl;
  }
  else{
    cout << "Odd" << endl;
  }
  return;
}

int main (){
  int a = 0, b = 0;
  cin >> a >> b;
  check (a*b);
 
}
