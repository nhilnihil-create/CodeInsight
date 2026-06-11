#include <bits/stdc++.h>
using namespace std;
int main(){
int A,B,C,a,b,c;
  cin>>A>>B>>C;
  a=max(max(A,B),C);
  if(a==A){
  b=max(B,C);
  c=min(B,C);
  }
  else if(a==B){
  b=max(A,C);
    c=min(A,C);
  }
  else{
  b=max(A,B);
    c=min(A,B);
  
  }
cout<<a*10+b+c<<endl;
}