#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,D,E,K;
  cin>>A>>B>>C>>D>>E>>K;
  if(max(A,max(B,max(C,max(D,E))))-min(A,min(B,min(C,min(D,E))))>K){
    cout<<":("<<endl;
  }
  else{
    cout<<"Yay!"<<endl;
  }
}