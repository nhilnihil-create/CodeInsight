#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N,A;cin>>N>>A;
  
  int ans;
  
  ans=N%500;
  
  if(ans<=A){
    cout<<"Yes"<<endl;
  }  
  
  else if(N<=A){
    cout<<"Yes"<<endl;
  }  
  
  else{
    cout<<"No"<<endl;
  }
  
  return 0;
}
