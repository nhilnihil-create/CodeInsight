#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N ,A_i ,c = 30;
  cin >> N;
  
  rep(i,N){
    cin >> A_i;
    
    for(int j = 0; 1; j++){
      if(A_i == (A_i / 2) *2){
        A_i = A_i / 2;
        continue;
      }
      
      else{
        if(c > j){
          c = j;
          break;
        }
        else{
          break;
        }
      }
    }
  }
  
  cout << c << endl;
}
