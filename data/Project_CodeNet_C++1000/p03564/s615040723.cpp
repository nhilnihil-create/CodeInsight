#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin>>N>>K;
  int num=1;
  for(int i=0;i<N;i++){
    if(num<=K){
      num = num*2;
    }
    else{
      num+=K;
    }
  }
  cout<<num<<endl;
}