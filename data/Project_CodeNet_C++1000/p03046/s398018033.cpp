#include <bits/stdc++.h>
using namespace std;

int main() {
  int M,K,L;
  cin>>M>>K;
  L=exp2(M);
  if(M==1){
    if(K==0){
      cout<<"0 0 1 1"<<endl;
    }
    else{
      cout<<"-1"<<endl;
    }
  }
  else{
    if(K>=L){
      cout<<"-1"<<endl;
    }
    else{
      for(int i=0;i<L;i++){
        if(i!=K){
          cout<<i<<" ";
        }
      }
      cout<<K<<" ";
      for(int i=L-1;i>=0;i--){
        if(i!=K){
          cout<<i<<" ";
        }
      }
      cout<<K<<endl;
    }
  }
      
}
