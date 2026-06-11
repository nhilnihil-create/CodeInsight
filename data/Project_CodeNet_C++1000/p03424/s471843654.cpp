#include<bits/stdc++.h>
using namespace std;

int main(){
  string a;
  int N,b=0,c=0,d=0,e=0,sum=0;
  cin >> N;
  
  for(int i=0;i<N;i++){
    cin >> a;
    if(a=="P"){
      b++;}
    else if(a=="G"){
      c++;}
    else if(a=="W"){
      d++;}
    else if(a=="Y"){
      e++;}
  }
 
  sum =b*c*d*e;
  if(sum==0){
    cout<<"Three"<<endl;}
  else {
    cout<<"Four"<<endl;}
}