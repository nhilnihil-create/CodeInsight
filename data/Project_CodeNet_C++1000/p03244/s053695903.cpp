#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  map<int,int>even;
  map<int,int>odd;
  for(int i=0;i<n;i+=2)
    even[a.at(i)]++;
  for(int i=1;i<n;i+=2)
    odd[a.at(i)]++;
  vector<pair<int,int>>eve(even.size()+1);
  vector<pair<int,int>>od(odd.size()+1);
  eve.at(0)=make_pair(0,0);
  od.at(0)=make_pair(0,0);
  int c=1;
  for(auto x:even){
    eve.at(c)=make_pair(x.second,x.first);
    c++;
  }
  c=1;
  for(auto x:odd){
    od.at(c)=make_pair(x.second,x.first);
    c++;
  }
  sort(od.begin(),od.end(),greater());
  sort(eve.begin(),eve.end(),greater());
  int ans=0;
  if(od.at(0).second==eve.at(0).second){
    if(od.at(0).first=eve.at(0).first){
      if(od.at(1).first>eve.at(1).first)
        ans=n-eve.at(0).first-od.at(1).first;
      else
        ans=n-od.at(0).first-eve.at(1).first;
    }else if(od.at(0).first>eve.at(0).first){
      ans=n-od.at(0).first-eve.at(1).first;
    }else{
      ans=n-eve.at(0).first-od.at(1).first;
    }
  }else{
    ans=n-eve.at(0).first-od.at(0).first;
  }
  cout << ans << endl;
  return 0;
}