#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B;
  cin >> A >> B;
  bool exist = false;
  for(int C = 1; C <= 3; C++){
    if((A * B * C) % 2 != 0)
      exist = true;
  }
  if(exist) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
