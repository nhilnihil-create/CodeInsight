#include<bits/stdc++.h>
using namespace std;
int main(){
int N,T;
  cin>>N>>T;
 
  vector<int> A(N);
  vector<int> B(N);
  for(int i=0;i<N;i++){
  cin>>A[i]>>B[i];
  }
   int b=1001;
  for(int i=0;i<N;i++){
  if(T>=B[i]){
  b=min(b,A[i]);
  }
  }
  if(b==1001){
  cout<<"TLE"<<endl;
  }else{
   cout<<b<<endl; 
  }
  
}
