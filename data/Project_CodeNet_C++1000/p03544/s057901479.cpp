#include <bits/stdc++.h>
using namespace std;



int main(void){
  int N;
  cin >> N ;
  vector<int64_t> L(87);
  L[0]=2;
  L[1]=1;
  if(N==0){
    cout << L[0] << endl;
    return 0;
  }
  if(N==1){
    cout << L[1] << endl;
    return 0;
  }
  
  for(int i=2;i<N+1;i++)
    L[i]=L[i-1]+L[i-2];
  
  cout << L[N] << endl;
}


      
  