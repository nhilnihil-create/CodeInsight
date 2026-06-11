#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,B,C=0,D;
  
  cin>>N;
  A=N;
  while(A>=1){
     B=A%10;
    A=A/10;
   
    C=C+B;}
//cout<<C<<endl;
  D=N%C;
  
  if(D==0){
    cout<<"Yes"<<endl;}
else{
    cout<<"No"<<endl;}
}