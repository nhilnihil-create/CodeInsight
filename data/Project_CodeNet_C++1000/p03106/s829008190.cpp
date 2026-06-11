#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,K,j=0;
  cin>>A>>B>>K;
  int i=min(A,B);
  for(;j<K;i--)
    if(A%i==0 && B%i==0)
      j++;
  cout<<i+1<<endl;
}