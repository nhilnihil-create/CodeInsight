#include <bits/stdc++.h>
using namespace std;
main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i= 0;i<N;i++) cin >> A[i];
  int cnt=0;
  while(true){
    bool odd=false;
    for(int i=0;i<N;i++){
      if(A[i]%2 == 1) odd=true;
    }
    if(odd) break;
    for(int i=0;i<N;i++){
      A[i] /=2;
    }
    cnt++;
  }
  cout << cnt <<endl;
}