#include <iostream>
using namespace std;
 
int main(){
  int N;
  int A[210];
  int res = 0;
  cin >> N;
  for(int i=0;i<N;i++)cin >> A[i];
  
  while(true){
  	bool ext_odd = false;
    for(int i=0;i<N;i++){
    	if(A[i] % 2 == 1) ext_odd = true;
    }
    if(ext_odd) break;
    for(int i=0;i<N;i++){
      A[i] = A[i] / 2;
    }
    ++res;
  }
  
  cout << res << endl;
  
}