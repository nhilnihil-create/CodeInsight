#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  int prod;
  
  cin>>N>>A>>B;
  prod=A*N;
  
  if(prod<=B) cout<<prod<<endl;
  else cout<<B<<endl;
  
  return 0; 
}