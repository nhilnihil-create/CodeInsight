#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,i,ans=0;
  cin>>n;
  vector<int64_t> a(n),b(n),c(n),bc(n);
  for(i=0;i<n;i++) cin>>a.at(i);
  for(i=0;i<n;i++) cin>>b.at(i);
  for(i=0;i<n;i++) cin>>c.at(i);
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  for(i=n-1;i>=0;i--){
    bc.at(i)=distance(upper_bound(c.begin(),c.end(),b.at(i)),c.end());
    if(i<n-1) bc.at(i)+=bc.at(i+1);
  }
  for(i=0;i<n;i++){
    if(upper_bound(b.begin(),b.end(),a.at(i))!=b.end()){
      ans+=bc.at(distance(b.begin(),upper_bound(b.begin(),b.end(),a.at(i))));
    }
  }
  cout<<ans<<endl;
}