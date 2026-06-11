#include<iostream>
using namespace std;
int main(){
int N,A,B,C,D;
  cin>>N>>A>>B;
  C = N*A;
  D = B;
  if(C>D){
  cout<<D<<endl;
  }
 else if(D>=C){
  cout<<C<<endl;
  }
return 0;
}
