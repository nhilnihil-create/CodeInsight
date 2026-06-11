#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,p,m=0,ans=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>p;
    ans+=p;
    if(m<p) m=p;
  }
  cout<<ans-m/2<<endl;
}