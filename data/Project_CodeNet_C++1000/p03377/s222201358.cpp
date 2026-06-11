#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int A,B,C;
  cin>>A>>B>>C;
  if(A<=C){
    if(A+B-C>=0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  else cout<<"NO"<<endl;
  
}