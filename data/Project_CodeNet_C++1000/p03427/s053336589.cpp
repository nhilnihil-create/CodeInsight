#include <bits/stdc++.h>
using namespace std;
long long n,i,j,c,x,a,b;
bool res=true;
int main(){
  for(cin>>n,x=n;n!=0;i++)n/=10;
  for(;j<i-1;j++){
    if(x%10!=9)res=false;
    c+=9,x/=10;
  }
  if(i==1)cout<<x;
  else cout<<(res?c+x:c+x-1);
}