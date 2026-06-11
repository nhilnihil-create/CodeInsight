#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,x,y,i,r,ans=1;
  cin>>n>>m;
  map<int,int> z;
  vector<pair<int,int>> v;
  for(i=0;i<m;i++){
    cin>>x>>y;
    if(!z.count(x)) z[x]=y;
    else if(y<z.at(x)) z.at(x)=y;
  }
  for(auto w:z) v.push_back(make_pair(w.first,w.second));
  r=v.at(0).second;
  for(i=1;i<(int)v.size();i++){
    if(r<=v.at(i).first){
      ans++;
      r=v.at(i).second;
    }
    else if(r>v.at(i).second){
      r=v.at(i).second;
    }
  }
  cout<<ans<<endl;
}