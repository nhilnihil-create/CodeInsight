#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int j=N;
  for(int i=0;i<=N;i++){
    int k=0;
    for(int l=i;l>0;l/=6)
      k+=l%6;
    for(int l=N-i;l>0;l/=9)
      k+=l%9;
    j=min(j,k);
  }
  cout<<j<<endl;
}