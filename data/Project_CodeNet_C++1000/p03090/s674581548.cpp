#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  if(N%2==0){
  cout<<(N*(N-2))/2<<endl;
    for(int i=1;i<=N-1;i++){
    for(int j=i+1;j<=N;j++){
    if(j!=N+1-i){
    cout<<i<<" "<<j<<endl;
    }
    
    }
    }
  }else{
  cout<<((N-1)*(N-1))/2<<endl;
    for(int i=1;i<=N-1;i++){
    for(int j=i+1;j<=N;j++){
      if(j!=N-i){
      cout<<i<<" "<<j<<endl;
      }
    }
    }
  }
   return 0;
}
