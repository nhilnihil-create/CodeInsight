#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()

int main(){
  int64_t N;
  cin>>N;
  vector<int64_t> A(N),B(N),C(N);
  for(int64_t &i:A)
    cin>>i;
  for(int64_t &i:B)
    cin>>i;
  for(int64_t &i:C)
    cin>>i;
  sort(all(A));
  sort(all(B));
  sort(all(C));
  int64_t o=0;
  for(int64_t &i:B){
    int64_t l=0,r=N,p;
    while(r-l!=1){
      int64_t j=(l+r)/2;
      if(A.at(j)<i)
        l=j;
      else
        r=j;
    }
    if(A.at(0)>=i)
      r=0;
    if(A.at(N-1)<i)
      r=N;
    p=r;
    l=0;
    r=N;
    while(r-l!=1){
      int64_t j=(l+r)/2;
      if(C.at(j)<=i)
        l=j;
      else
        r=j;
    }
    if(C.at(0)>i)
      r=0;
    if(C.at(N-1)<=i)
      r=N;
    o+=p*(N-r);
  }
  cout<<o<<endl;
}