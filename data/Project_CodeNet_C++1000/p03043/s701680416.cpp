#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,i,j;
  double ans=0.0;
  cin>>n>>k;
  j=1;
  for(i=n;i>0;i--){
    while(j*i<k) j*=2;
    ans+=1.0/j;
  }
  ans*=1.0/n;
  cout<<fixed<<setprecision(12)<<ans<<endl;
}