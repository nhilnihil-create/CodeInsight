#include <iostream>
using namespace std;
int main(){
  int N;
  cin >> N;
  int A[201];
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  
  int count = 0;
  while(true){
    bool can = false;
    
    for(int i = 0; i < N; i++){
      if(A[i] % 2 != 0){
        can = true;
      }
    }
      
    if(can){
      break;
    }
      
    for(int i = 0; i < N; i++){
      A[i] /= 2;
    }
    count++;
  }
  cout << count << endl;
}
    
