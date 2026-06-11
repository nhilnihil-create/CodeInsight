#include<bits/stdc++.h>
using namespace std;

int main(){
int A,s;
  cin>>A;
  s=A%1000;
  if(A%1110<10 || s%111==0 || s==0 ){
  cout<<"Yes"<<endl;
  }else {
  cout<<"No"<<endl;
  }
}