#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,K;
  cin>>A>>B>>K;
  if(B-K+1<=A+K-1){
  for(int i=A;i<B+1;i++)
    cout<<i<<endl;
  }
    else{
  
  for(int i=A;i<A+K;i++){
    cout<<i<<endl;
  }
  for(int i=B-K+1;i<B+1;i++)
    cout<<i<<endl;
    }
}