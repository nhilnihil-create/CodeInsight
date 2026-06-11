#include<bits/stdc++.h>
using namespace std;

int main(){
 
  int a,b;
  cin >> a >> b;
  int num[1000];
  num[0] = 0;
  for(int i = 0; i < 999; i++){
    num[i + 1] = num[i] + i + 1;
  } 

  for(int i = 1; i < 999; i++){
    if(num[i] - a == num[i + 1] - b){ cout << num[i] - a << endl; return 0; }
  }
  return 0;
}