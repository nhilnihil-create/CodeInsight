#include<bits/stdc++.h>
using namespace std;

int main(){
  int fo,o,f;
  int kin;
  int cnt = 0;
  
  cin >> fo >> o >> f >> kin;
  
  for(int i = 0; i <= fo; i++){
    for(int j = 0; j <= o; j++){
      for(int k = 0; k <= f; k++){
        if(500*i + 100*j + 50*k == kin) cnt++;
      }
    }
  }
  
  cout << cnt;
}
