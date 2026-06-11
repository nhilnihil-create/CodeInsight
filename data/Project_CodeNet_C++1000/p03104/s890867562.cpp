#include<bits/stdc++.h>
using namespace std;
int main(){
  long long A,B;
  cin>>A>>B;
  A--;
  uint64_t C,D;
  if(A==-1)C=0;
  else if(A%4==1)C=1;
  else if(A%4==2)C=A+1;
  else if(A%4==3)C=0;
  else C=A;
  if(B%4==1)D=1;
  else if(B%4==2)D=B+1;
  else if(B%4==3)D=0;
  else D=B;
  cout<<(C^D)<<endl;
}