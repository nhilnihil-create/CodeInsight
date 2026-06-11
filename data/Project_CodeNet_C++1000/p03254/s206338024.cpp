#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,X;
  cin>>N>>X;
  vector<int> A(N);
  for(int i=0;i<N;i++){
      cin >> A[i];
  }
  int H=0;
  sort(A.begin(), A.end());
  for(int i=0;i<N;i++) {
    if(X-A[i]<0){ 
        break;
    }
    if(i==N-1&&X-A[i]!=0) {
        break;
    }
      X-=A[i];
      H++;
}
  cout << H;
  return 0;
}
