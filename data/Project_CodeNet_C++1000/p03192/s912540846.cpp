#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,j=0;
  cin>>N;
  for(;N>0;N/=10)
    if(N%10==2)
      j++;
  cout<<j<<endl;
}