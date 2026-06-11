#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,X;
  cin>>N>>M>>X;
  int j=0;
  for(int i=0;i<M;i++){
    int k;
    cin>>k;
    if(k>X)
      break;
    j++;
  }
  cout<<min(j,M-j)<<endl;
}