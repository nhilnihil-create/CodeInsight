#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  int64_t c=0;
  for(int b=k+1;b<=n;b++)
    for(int x=0;x<=n/b;x++)
      c+=max(min(n-x*b,b-1)+1-k,0);
  cout<<c-(k==0?n:0)<<endl;
}