#include<bits/stdc++.h>
using namespace std;
int main(){
  long long A,B;
  int K;
  cin>>A>>B>>K;
  if(B-A+1<=2*K){
    for(int i=A;i<B+1;i++){
      cout<<i<<endl;
    }
  }
  else{
    for(int i=0;i<K;i++){
      cout<<A+i<<endl;
    }
    for(int i=0;i<K;i++){
      cout<<B+1-K+i<<endl;
    }
  }
}
