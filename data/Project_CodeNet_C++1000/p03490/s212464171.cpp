#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  int x,y;cin>>x>>y;
  vector<int> v,w;
  int now=0;
  int c=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='F')now++;
    else{
        if(c==0)v.push_back(now);
        else w.push_back(now);
      
      c=c^1;
      now=0;
    }
  }
  
    if(c==0)v.push_back(now);
    else w.push_back(now);
  
  bool used[16001];
  fill(used,used+16001,false);
  used[8000]=true;
  for(int i=0;i<v.size();i++){
    if(i==0){
      used[8000+v[0]]=true;
      continue;
    }
    bool us[16001];
    fill(us,us+16001,false);
    for(int j=0;j<16001;j++){
      if(used[j]==false)continue;
      us[j+v[i]]=true;
      us[j-v[i]]=true;
    }
    for(int i=0;i<16001;i++)used[i]=us[i];
  }
  if(used[8000+x]==false){
    cout<<"No"<<endl;
    return 0;
  }
  fill(used,used+16001,false);
  used[8000]=true;
  for(int i=0;i<w.size();i++){
    bool us[16001];
    fill(us,us+16001,false);
    for(int j=0;j<16001;j++){
      if(used[j]==false)continue;
      us[j+w[i]]=true;
      us[j-w[i]]=true;
    }
    for(int i=0;i<16001;i++)used[i]=us[i];
  }
  if(used[y+8000]==false)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}