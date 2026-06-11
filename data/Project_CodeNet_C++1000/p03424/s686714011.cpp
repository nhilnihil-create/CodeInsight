#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k=1,i=0;
  cin >>n;
  while(i<n){
    string c;
    cin >>c;
    if(c=="Y"){
      cout <<"Four"<<endl;
      k=0;
      break;
    }
    else{
    i++;}
  }
  if(k!=0){
    cout <<"Three"<<endl;
  }
}
   
  