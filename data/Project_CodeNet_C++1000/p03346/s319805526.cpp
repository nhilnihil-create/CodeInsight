#include <iostream>
using namespace std;
int A[200005]={0};
int main(){long n;cin>>n;int ans=1;int z=1;
  for(int i=1;i<=n;i++){int p;cin>>p; A[p]=i;}
  int r=A[1];
  for(int i=2;i<=n;i++){if(A[i]>r){z++;if(ans<z)ans=z;}else{if(ans<z){ans=z;}z=1;}r=A[i];}
  cout<<n-ans<<endl;}