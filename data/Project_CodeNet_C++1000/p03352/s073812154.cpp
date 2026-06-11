#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,k=1;
  cin>>X;
  for(int i=2;i<=X/i;i++){
    int j=i*i;
    for(;j<=X;j*=i){}
    k=max(k,j/i);
  }
  cout<<k<<endl;
}