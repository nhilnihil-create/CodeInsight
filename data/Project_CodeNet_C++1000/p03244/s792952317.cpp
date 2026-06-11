#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >>n;
  vector<int>v(n);
  map<int,int>a;
  map<int,int>b;
  for(int i=0;i<n;i++)cin>>v[i];
  for(int i=0;i<n;i++){
    if(i%2==0){
      if(a.count(v[i]))a.at(v[i])++;
      else a[v[i]]=1;
    }else{
      if(b.count(v[i]))b.at(v[i])++;
      else b[v[i]]=1;
    }
  }
  int dai_a=0;
  int dai_ai;
  auto begin=a.begin(),end=a.end();
  for(auto iter=begin;iter!=end;iter++){
    if(dai_a<iter->second){
      dai_a=iter->second;
      dai_ai=iter->first;
    }
  }
  int dai_b=0;
  int dai_bi;
  auto c=b.begin(),d=b.end();
  for(auto iter=c;iter!=d;iter++){
    if(dai_b<iter->second){
      dai_b=iter->second;
      dai_bi=iter->first;
    }
  }
  int kotae=0;
  if(dai_ai!=dai_bi){
    kotae=n-dai_a-dai_b;
    cout<<kotae<<endl;
    return 0;
  }else{
    if(dai_a+dai_b==n){
      kotae=n-dai_a;
      cout<<kotae<<endl;
      return 0;
    }else{
      int dai_b2=0;
      auto c=b.begin(),d=b.end();
      for(auto iter=c;iter!=d;iter++){
        if(dai_bi!=iter->first)dai_b2=max(dai_b2,iter->second);
      }
      int dai_a2=0;
      auto begin=a.begin(),end=a.end();
      for(auto iter=begin;iter!=end;iter++){
      if(dai_ai!=iter->first)dai_a2=max(dai_a2,iter->second);
      }
      if(dai_a+dai_b2>=dai_a2+dai_b){
        kotae=n-dai_a-dai_b2;
        cout<<kotae<<endl;
        return 0;
      }else{
        kotae=n-dai_a2-dai_b;
        cout<<kotae<<endl;
        return 0;
      }
    }
  }
  return 0;
}