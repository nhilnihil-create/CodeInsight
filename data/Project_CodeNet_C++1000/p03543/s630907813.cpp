#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,L,R,X,Y;
  cin>>N;
  L=(N%1000);
  R=N%10;
  
  X=L%111;
  Y=(N-R)%111;
  
  if(X==0||Y==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  
  
  
}