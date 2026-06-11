#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  long long C[500],S[500],F[500];
  for(int i=0;i<N-1;i++) cin>>C[i]>>S[i]>>F[i];
  for(int i=0;i<N-1;i++){
    long long answer=S[i]+C[i];
    for(int j=i+1;j<N-1;j++){
      if(answer<S[j]) answer=S[j]+C[j];
      else answer+=(F[j]-answer%F[j])%F[j]+C[j];
    }
    cout<<answer<<endl;
  }
  cout<<0<<endl;
  
  return 0;
}