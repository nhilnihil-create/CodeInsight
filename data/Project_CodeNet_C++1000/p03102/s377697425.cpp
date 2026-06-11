#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M,C;
  cin>>N>>M>>C;
  vector<int> B(M);
  for(int &i:B)
    cin>>i;
  int l=0;
  while(N--){
    int k=C;
    for(int i=0;i<M;i++){
      int A;
      cin>>A;
      k+=A*B[i];
    }
    if(k>0)
      l++;
  }
  cout<<l<<endl;
}