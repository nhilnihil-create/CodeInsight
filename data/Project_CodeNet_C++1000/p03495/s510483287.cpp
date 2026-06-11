#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
  vector<int>A(N,0);
  for(int i=0;i<N;i++){
    int k;cin>>k;
    A.at(k-1)++;
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  if(K==N){
    cout<<0<<endl;
  }
  else{
    int sum=0;
    for(int i=K;i<N;i++){
      sum=sum+A[i];
    }
    cout<<sum<<endl;
  }
}
      
    