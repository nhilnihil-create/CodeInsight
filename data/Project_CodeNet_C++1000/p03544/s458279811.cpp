#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, L0, L1, L;
  cin >> N;
  
  L0=2;
  L1=1;
  
  for(int i=0;i<N;i++){
    if(i==0){
      L=1;
    }else{
      L=L1+L0;
      L0=L1;
      L1=L;
    }
  }
  
  cout << L << endl;
}
