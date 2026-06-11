#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<bool> A(55560,true);
  A[0]=false,A[1]=false;
  for(int i=2;i<=55555/i;i++){
    if(!A[i])continue;
    for(int j=i*2;j<=55555;j+=i)
      A[j]=false;
  }
  vector<int> B(0);
  for(int i=1;i<=55555;i+=5)
    if(A[i])B.push_back(i);
  for(int i=0;i<N;i++){
    cout<<B[i];
    if(i==N-1)
      cout<<'\n';
    else
      cout<<' ';
  }
}