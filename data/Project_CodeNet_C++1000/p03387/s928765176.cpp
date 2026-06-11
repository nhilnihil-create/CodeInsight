#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int>A(3);
  cin>>A[0]>>A[1]>>A[2];
  sort(A.begin(),A.end());
  int B=A[1]-A[0];
  int C=A[2]-A[1];
  if(B%2==0){
    cout<<C+B/2<<endl;
  }
  else{
    cout<<C+2+B/2<<endl;
  }
}