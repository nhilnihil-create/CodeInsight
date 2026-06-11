#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,x,l,i,ans=0;
  map<int,int> m;
  vector<int> v;
  cin>>n>>k;
  for(i=0;i<n;i++){
    cin>>x;
    if(m.count(x)) m.at(x)++;
    else m[x]=1;
  }
  for(auto z:m) v.push_back(z.second);
  sort(v.begin(),v.end());
  l=v.size();
  for(i=0;i<l-k;i++) ans+=v.at(i);
  cout<<ans<<endl;
}