#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C,a,b,c;
  cin>>A>>B>>C;
  a=max(max(A,B),C);
  b=min(min(A,B),C);
  cout<<a-b<<endl;
 
  
  }
  
