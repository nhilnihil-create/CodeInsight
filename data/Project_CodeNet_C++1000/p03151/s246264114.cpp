#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,g=0;
  cin>>N;
  vector<int> A(N),B(N),C(N);
  for(int &i:A)
    cin>>i;
  for(int &i:B)
    cin>>i;
  for(int i=0;i<N;i++)
    C[i]=B[i]-A[i];
  sort(C.begin(),C.end());
  if(C[N-1]<=0){
    cout<<0<<endl;
    return 0;
  }
  int i=N-1;
  for(;i>=0;i--){
    if(C[i]<=0)
      break;
    g+=C[i];
  }
  for(int j=0;j<=i;j++){
    g+=C[j];
    if(g<=0){
      cout<<N-(i-j)<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}