#include<bits/stdc++.h>
using namespace std;

int main(void){
  char n[3];
  for(int i = 0; i < 3; i++)
    cin >> n[i];
  for(int i = 0; i < 3; i++){
    if(n[i] == '1')
      n[i] = '9';
    else if(n[i] == '9')
      n[i] = '1';
  }
  for(int i = 0; i < 3; i++)
    cout << n[i];
  cout << "\n";
  return 0;
}
