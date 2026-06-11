#include <bits/stdc++.h>
using namespace std;
int main(){
int A,B;
  cin>>A>>B;
  bool nazo =false;
  int d=A*B;
  for(int i=1;i<4;i++){
  	if((d*i)%2 == 1){
    nazo=true;
    }
  }
  if(nazo){
  cout<<"Yes";
  }
  else{
  cout<<"No";
  }
}