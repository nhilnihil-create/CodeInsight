#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,ans=0;
  cin>>n;
  vector<int> a(n);
  for(i=0;i<n;i++) cin>>a.at(i);
  for(i=0;i<n;i++) ans+=a.at(i)-1;
  cout<<ans<<endl;
}