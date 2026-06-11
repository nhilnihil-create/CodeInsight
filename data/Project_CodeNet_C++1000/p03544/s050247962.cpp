#include <bits/stdc++.h>
using namespace std;
//ｎ番目のリュカ数を返す関数


int main() {
  int N;
  cin >> N ;
  int64_t L2=0;
  if(N==1){
    L2=1;
  }
 
  
  else{
  int64_t L0=2;
  int64_t L1=1;
    L2=0;
  
    for(int i=0; i<N-1; i++){
      L2=L1+L0;
      L0=L1;
      L1=L2;
      
    }
  }
  
  
  cout << L2 << endl;
}
