#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  double A[N],B[N],suma,sumb,cnt;
  suma=0;
  sumb=0;
  cnt=0;
  for (int i=0;i<N;i++){
    cin>>A[i];
    suma=suma+A[i];
  }
  for (int i=0;i<N;i++){
    cin>>B[i];
    sumb=sumb+B[i];
  }  
  for(int i=0;i<N;i++){
    if(A[i]<B[i]){
      cnt+=ceil((B[i]-A[i])/2);
    }
  }
  //cout<<sumb<<" "<<suma<<" "<<cnt<<endl;

  if(sumb-suma>=cnt){
    cout<<"Yes"<<endl;
  }
  else cout<<"No"<<endl;
  return 0;
}
