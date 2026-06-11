#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,b,i,ans=0;
  cin>>n;
  vector<int64_t> a(n);
  for(i=0;i<n;i++){
    cin>>b;
    a.at(i)=b-i-1;
  }
  sort(a.begin(),a.end());
  b=a.at((n-1)/2);
  for(i=0;i<n;i++) ans+=abs(a.at(i)-b);
  cout<<ans<<endl;
}