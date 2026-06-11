#include <bits/stdc++.h>
using namespace std;
int main(void){
  char n[3];
  cin >> n;
  for(int i=0;i<3;i++){
    if(n[i] == '1') n[i] = '9';
    else n[i] = '1';
  }
  cout << n << endl;
}