#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,k,l,m,ans;
  cin>>n>>k;
  l=n/k;
  ans=l*l*l;
  if(k%2==0){
    m=n/(k/2)-l;
    ans+=m*m*m;
  }
  cout<<ans<<endl;
}