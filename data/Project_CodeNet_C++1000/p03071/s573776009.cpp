#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin>>A>>B;
  int x;
  if(A>B){
    x=2*A-1;
  }
  else if(A<B){
    x=2*B-1;
  }
  else{
    x=2*A;
  }
  cout<<x<<endl;
}