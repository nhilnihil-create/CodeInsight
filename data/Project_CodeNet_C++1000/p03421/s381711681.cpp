#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;


signed main() {
 int n,a,b;
 cin>>n>>a>>b;
 if(n<a+b-1||n>a*b){
   cout<<-1;
   return 0;
 }
 if(b==1){
   for(int i=1;i<=n;i++)cout<<i<<' ';
   return 0;
 }
  if(a==1){
   for(int i=1;i<=n;i++)cout<<n+1-i<<' ';
   return 0;
 }
  int k=(n-a)/(b-1),t=(n-a)%(b-1);
  for(int i=0;i<k;i++){
    for(int j=b;j>0;j--)cout<<i*b+j<<' ';
  }
  if(n!=a*b){
  for(int i=t+1;i>0;i--)cout<<k*b+i<<' ';
  for(int i=a-k-1;i>0;i--)cout<<n+1-i<<' ';}
  return 0;
}
