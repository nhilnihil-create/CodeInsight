#include<bits/stdc++.h>
using namespace std;
int g(int a,int b){
  if(a>b)
    return g(b,a);
  if(a==0)
    return b;
  return g(b%a,a);
}
int main(){
  int a,b,k;
  cin>>a>>b>>k;
  int c=0;
  for(int i=g(a,b);c<k;i--){
    if(g(a,b)%i==0)
      c++;
    if(c==k)
      cout<<i<<endl;
  }
}