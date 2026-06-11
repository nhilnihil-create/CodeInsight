#include<bits/stdc++.h>
using namespace std;
int main() {
  int N,A,B; cin>>N>>A>>B;
  int a=0,b=0;
  a=min(A,B);
  b=A+B-N;
  if(b<0) b=0;
  cout<<a<<" "<<b<<endl;
}