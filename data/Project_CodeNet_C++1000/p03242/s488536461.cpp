#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a,b,c;
  if(n%10==1){
    n+=8;
  }
  else{
    n-=8;
  }
  if(n%100==19||n%100==11){
    n+=80;
  }
  else{
    n-=80;
  }
  if(n==111||n==119||n==191||n==199){
    n+=800;
  }
  else{
    n-=800;
  }
  cout<<n;
}