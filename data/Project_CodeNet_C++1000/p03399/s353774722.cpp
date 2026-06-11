#include<iostream>
using namespace std;
int main(){
int A,B,C,D;
  cin>>A>>B>>C>>D;
  int ans=0;
  if (A>=B){
    ans+=B;
  }
  else ans+=A;
  if (C>=D){
    ans+=D;
  }
  else ans+=C;
  cout<< ans << endl;
 return 0;}
