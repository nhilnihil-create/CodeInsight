#include <bits/stdc++.h>
using namespace std;
int main (){
  int N,A,n,k;
  cin>>N;
  for(int i=0;i<N;i++){
      n=0;
    cin>>A;
    for(int j=0;true;j++){
      if(A%2==0){
        n++;
        A/=2;
      }
      else{
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
  

