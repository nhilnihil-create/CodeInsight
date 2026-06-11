#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N,S;cin>>N>>S;
  vector<long long>A(N);
  long long K=0;
  for(int X=0;X<N;X++){
    cin>>A[X];
    K+=A[X];
  }
  sort(A.begin(),A.end());
  if(K<S){
    cout<<N-1<<endl;
  }
  else{
    int Y;long long M=0;
    for(Y=0;Y<N;Y++){
      M+=A[Y];
      if(M>S){
        break;
      }
    }
    cout<<Y<<endl;
  }
}