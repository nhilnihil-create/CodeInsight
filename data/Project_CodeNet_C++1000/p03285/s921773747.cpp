#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int up_c = N/4;
  int up_d = N/7;
  
  bool can = false;
  
  for(int i=0; i< (up_c + 1); i++){
    for(int j=0; j<(up_d+ 1);j++){
      int amount = 4*i + 7*j;
      if(amount == N){
        can = true;
        break;
      }
    }
    if(can) break;
  }
  
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
}