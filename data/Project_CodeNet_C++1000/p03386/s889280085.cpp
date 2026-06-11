#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, K;
  cin>>A>>B>>K;
  int C=A+K;
  int D=B-K+1;
  if(C<D){
  for(int i=A; i<C; i++) cout<<i<<endl;
  for(int i=D; i<=B; i++) cout<<i<<endl;
  }
  else{
    for(int i=A; i<=B; i++) cout<<i<<endl;
  }
}
