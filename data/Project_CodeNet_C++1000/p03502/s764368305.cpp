#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string N;
  cin>> N;
  int sum=0;
  int c = N.size();
  for(int i=0;i<c;i++){
  int a = N[i] - '0';
  //cout<<i<<":"<<a<<endl;
    sum+=a;
    //cout<<sum<<endl;
  }
  istringstream ss1;
  int M;
  ss1= istringstream(N);
  ss1>> M;
 // cout<<M<<endl;
  //cout<<sum<<endl;
  if ( M%sum == 0 ) {
  cout<<"Yes"<<endl; 
  }
  else{
  cout<<"No"<<endl;}
}