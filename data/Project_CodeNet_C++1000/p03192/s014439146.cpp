#include <bits/stdc++.h>
using namespace std;

int func(int N){
  if(N<10){ return (N==2);}
  else{ return func(N/10)+(N%10==2);}
}
int main(){
  int N;cin>>N;
  cout<<func(N);
}