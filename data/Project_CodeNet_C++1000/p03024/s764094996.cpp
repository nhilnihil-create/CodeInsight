#include <bits/stdc++.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main(){
  string S;
  cin>>S;
  int N=S.size();
  int count=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='x') count++;
  }
  
  if(count>7) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}