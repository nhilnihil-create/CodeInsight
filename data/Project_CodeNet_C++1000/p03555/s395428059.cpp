#include<bits/stdc++.h>
using namespace std;
int main(){
  string A,B;
  cin>>A>>B;
  string C=A;
  string D=B;
  reverse(C.begin(),C.end());
  reverse(D.begin(),D.end());
  if(A==D&&B==C){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}