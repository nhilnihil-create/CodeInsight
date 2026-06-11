#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B;
  cin>>A>>B;
  if(A>=13){
    cout<<B<<endl;
    return 0;
  }
  else if(A>=6&&A<13){
    cout<<B/2<<endl;
    return 0;
  }
  else{
    cout<<0<<endl;
    return 0;
  }
}