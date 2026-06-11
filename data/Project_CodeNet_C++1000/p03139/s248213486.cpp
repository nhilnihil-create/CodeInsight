#include<bits/stdc++.h>
using namespace std;
int main(){
  long long h,w,p,n,a,b;
  cin>>n>>a>>b;
  if(a>=b)
  cout<<b<<" ";
  else
  cout<<a<<" ";
  h=a+b-n;
  if(h<=0)
  cout<<0;
  else
  cout<<h;
  
  
  return 0;
}
