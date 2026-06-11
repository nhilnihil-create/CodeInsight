#include<bits/stdc++.h>
using namespace std;
int main(){
  int M,K;
  cin>>M>>K;
  int N=pow(2,M);
  if(N<=K ||(N==2 && K==1))
    cout<<-1<<endl;
  else if(N==2 && K==0)
    cout<<0<<" "<<1<<" "<<1<<" "<<0<<endl;
  else{
  vector<int>A;
    for(int i=0;i<N;i++){
    if(i!=K)
      A.push_back(i);
    }vector<int>B;
    B.push_back(K);
    for(int i=0;i<N-1;i++)
      B.push_back(A[i]);
    B.push_back(K);
    for(int i=0;i<N-1;i++)
      B.push_back(A[N-2-i]);
    for(int i=0;i<2*N-1;i++)
      cout<<B[i]<<" ";
    cout<<B[2*N-1]<<endl;
  }
  return 0;
}