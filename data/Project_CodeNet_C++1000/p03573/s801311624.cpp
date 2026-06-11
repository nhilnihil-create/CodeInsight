#include <iostream>
using namespace std;

int main()
{ 
  int A,B,C;
  cin>>A>>B>>C;
  if(A==B){
    cout<<C; 
  }
  else if (C==B){
    cout<<A;
  }
  else {
    cout<<B;
  }  
  return 0; 
}