#include <bits/stdc++.h>
using namespace std;
int main (){
  int N,m,A,n,k;
  cin>>N;
  m=2;
  for(int i=0;i<N;i++){
      n=0;
    cin>>A;
    for(int j=0;true;j++){
      if(A%m==0){
        n++;
        m*=2;
      }
      else{
        m=2;
        break;
      }
    }
     if(i==0){
        k=n;
      }
      else{
        if(k>n){
          k=n;
        }
      }
  }
  cout<<k<<endl;
}
  

