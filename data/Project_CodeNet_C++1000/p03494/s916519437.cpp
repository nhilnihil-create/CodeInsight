#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int A[200];
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  
  int ans = 0;
  
  while(1){
    bool jud = false;
    for(int i = 0; i < N; i++){
      if(A[i] % 2 ==1){
        jud = true;
        break;
      }
    }
    
    if(jud){
      break;
    }
    
    ans++;
      
    for(int i = 0; i < N; i++){
      A[i] /= 2;
    }
  }
  cout << ans << endl;
  return 0;
}