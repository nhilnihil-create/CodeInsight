#include<bits/stdc++.h>
using namespace std;
signed main(){
  int n,c,res=0;
  cin>>n;
  if(n==1){
    cin>>c;
    cout<<c;
    return 0;
  }
  map<int,int> d;
  vector<int> t,ind;
  ++d[0];
  for(int i=0;i<n;++i){
    cin>>c;
    ++d[c];
  }
  for(auto p:d){
    if(p.second>2)return cout<<0,0;
    if(p.second==2){
      t.push_back(p.first);
      t.push_back(24-p.first);
    }
    if(p.second==1)ind.push_back(p.first);
  }
  for(int bit=0;bit<(1<<ind.size());++bit){
    vector<int> s(t);
    for(int i=0;i<ind.size();++i){
      if(bit>>i&1)s.push_back(24-ind[i]);
      else s.push_back(ind[i]);
    }
    sort(s.begin(),s.end());
    s.push_back(s[0]+24);
    int dif=24;
    for(int i=0;i<s.size()-1;++i)dif=min(dif,s[i+1]-s[i]);
    res=max(res,dif%24);
  }
  cout<<res;
}