#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,ans;
  cin>>n>>k;
  ans=(n-1)/(k-1);
  if((n-1)%(k-1)>0) ans++;
  cout<<ans<<endl;
}