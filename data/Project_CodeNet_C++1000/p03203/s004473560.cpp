#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,n;cin>>h>>w>>n;
  vector<int> v[h+1];
  for(int i=0;i<n;i++){
    int x,y;cin>>x>>y;
    v[x].push_back(y);
  }
  if(h==1){
    cout<<1<<endl;
    return 0;
  }
  for(int i=1;i<=h;i++)sort(v[i].begin(),v[i].end());
  int now=1;
  //int u=lower_bound(v[2].begin(),v[2].end(),1)-v[2].begin();
 // cout<<u;return 0;
  if(v[2].size()!=0&&v[2][0]==1){
    cout<<1<<endl;
    return 0;
  }
  for(int i=2;i<=h;i++){
    //cout<<i<<endl;
    if(i==h){
      cout<<h<<endl;
      return 0;
    }
    if(v[i].size()==0){
      now++;
    }
    else if(v[i][0]!=now+1){
      now++;
    }
    if(v[i+1].size()==0){
      continue;
    }
    //cout<<now<<c<<endl;
    if(v[i+1][0]<=now){
      cout<<i<<endl;
      return 0;
    }
  }
}