#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int A,B;
  cin>>A>>B;
  int pr;
  if(A>=13){
      pr=B;
  }
  else if(A>=6){
      pr=B/2;
  }
  else{
      pr=0;
  }
  cout<<pr<<endl;
  
}