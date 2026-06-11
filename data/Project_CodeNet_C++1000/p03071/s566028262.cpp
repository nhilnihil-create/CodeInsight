#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C;
  cin>>A>>B;
  C=max(A,B)+max(max(A,B)-1,min(A,B));
  cout<<C<<endl;
  
}
