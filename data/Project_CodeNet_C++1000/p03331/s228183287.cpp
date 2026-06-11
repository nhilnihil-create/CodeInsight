#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int l=72;
  for(int i=1;i<=(N+1)/2;i++){
    int j=0;
    for(int k=i;k>0;k/=10)
      j+=k%10;
    for(int k=N-i;k>0;k/=10)
      j+=k%10;
    l=min(l,j);
  }
  cout<<l<<endl;
}