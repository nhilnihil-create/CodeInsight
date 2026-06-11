#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;

int main() {
  int x,a,b,c,d,e;
  cin>>x;
 for(int i=1;i*i<=x;i++){
   a=i*i;
 }
 for(int i=1;i*i*i<=x;i++){
   b=i*i*i;
 }
 for(int i=1;i*i*i*i*i<=x;i++){
   c=i*i*i*i*i;
 }
  
  for(int i=1;i*i*i*i*i*i*i<=x;i++){
  d=i*i*i*i*i*i*i;
 }
  
  for(int i=1;i*i*i*i*i*i*i*i*i<=x;i++){
   e=i*i*i*i*i*i*i*i*i;
 }
  int f=max({a,b,c,d,e});
  cout<<f<<endl;
  
}