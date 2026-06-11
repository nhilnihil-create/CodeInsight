#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,X;
  cin>>N>>X;
  int A;
  cin>>A;
  A=abs(X-A);
  for(int i=1;i<N;i++){
    int a;
    cin>>a;
    a=abs(a-X);
    A=gcd(A,a);
  }
  cout<<A<<endl;
}