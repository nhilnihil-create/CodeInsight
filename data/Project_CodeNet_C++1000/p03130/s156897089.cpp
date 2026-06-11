#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,D,E,F;
  cin>>A>>B>>C>>D>>E>>F;
  if(A==C&&A==E){
    cout<<"NO"<<endl;
  }
  else if(A==C&&A==F){
    cout<<"NO"<<endl;
  }
  else if(B==C&&B==E){
    cout<<"NO"<<endl;
  }
  else if(A==D&&A==E){
    cout<<"NO"<<endl;
  }
  else if(A==D&&A==F){
    cout<<"NO"<<endl;
  }
  else if(B==C&&B==F){
    cout<<"NO"<<endl;
  }
  else if(B==D&&B==F){
    cout<<"NO"<<endl;
  }
  else if(B==D&&B==E){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES"<<endl;
  }
}