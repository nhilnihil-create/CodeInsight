#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin>>N>>A>>B;
  
  int T=N*A;
  
  if(T>B){
    cout<<B<<endl;
  }
  else if(T==B){
    cout<<B<<endl;
  }
  else{
    cout<<T<<endl;
}
}