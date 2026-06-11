#include <bits/stdc++.h>
using namespace std;

int main(){
  int x;
  cin>>x;
  long long  kotae=0;
  for(int i=1;i<=31;i++){
    for(int j=2;j<=10;j++){
      long long kazu=pow(i,j);
      if(kazu<=x)kotae=max(kazu,kotae);
      else break;
    }
  }
  cout<<kotae;
  return 0;
}