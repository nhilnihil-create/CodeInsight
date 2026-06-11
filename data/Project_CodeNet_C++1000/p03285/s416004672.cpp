#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  bool res = false;
  
  for(int i = 0; i<=25; i++){
    for(int j = 0; j<15; j++){
      int total = 4*i + 7*j;
      if(total == n){
        res = true;
        break;
      }
    }
    if(res)
      break;
  }
  if(res)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}