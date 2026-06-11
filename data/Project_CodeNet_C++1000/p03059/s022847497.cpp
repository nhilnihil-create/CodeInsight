#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B,T;
  cin>>A>>B>>T;
  int ans=0,C=0;
  T=(double)T+0.5;
  C=T/A;
  ans=B*C;
  cout<<ans<<endl;
}