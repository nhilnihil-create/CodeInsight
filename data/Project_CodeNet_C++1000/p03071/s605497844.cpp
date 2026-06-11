#include <bits/stdc++.h>
using namespace std;
int main(){
int A,B;
  cin>>A>>B;
  
  int c=max(A,B);
  if(A==B){
  cout<<A+B<<endl;
  }
  else{
  cout<<c+(c-1)<<endl;
  }
}